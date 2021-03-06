#ifndef JEJ_TEXTURE_COMPONENT_HPP
#define JEJ_TEXTURE_COMPONENT_HPP

#include <EntityComponentSys/Components/Component.hpp>

#include <Core/BaseStructs.hpp>
#include <External/OpenGL_ES2/GLES2/gl2.h>
#include <External/STB/stb_image.h>
#include <External/STB/stb_truetype.h>

#include <string>
#include <vector>

namespace jej
{

    class Entity;
    class Shape;

    class TextureComponent : public Component
    {

        friend class TextureSystem;
        friend class RenderSystem;
        friend class FileHandler;

    public:

        struct ShapeData
        {
            const JEJ_COUNT parentID;
            const JEJ_COUNT shapeID;
            int textureID;

            //Disabled default constructor
            ShapeData() = delete;
            NOCOPY(ShapeData);

            ShapeData(
                const JEJ_COUNT p_parentID,
                const JEJ_COUNT p_shapeID,
                const int p_textureID
                ) :
                parentID(p_parentID),
                shapeID(p_shapeID),
                textureID(p_textureID)
            {}
        };


        struct TextureData
        {
            std::string name;
            int x = 0;
            int y = 0;
            int offset = 0;
            unsigned int size = 0u;
            unsigned char* data = nullptr;
            int usingImage = -1;
            Vector2i imagesInTexture = Vector2i(0, 0);
            bool hasChanged = false;

            TextureData(){};
            ~TextureData()
            {
                if (data)
                {
                    stbi_image_free(data);
                    data = nullptr;
                }

            }

        };






        struct Font
        {
            stbtt_fontinfo fontInfo;
            unsigned char* fontData = nullptr;
            unsigned int fontDataSize = 0u;
            unsigned int fontOffset = 0;

            Font(){};
            NOCOPY(Font);
            ~Font()
            {
                //Free fontdata if present (also called in texcomp dtor)
                if (fontData)
                {
                    delete[] fontData;
                    fontData = nullptr;
                }
            }
        };




        //Constructor
        TextureComponent(Entity* p_entity, const JEJ_COUNT p_shapeID);
        TextureComponent(Entity* p_entity, Shape* p_shape);

        //Disabled copy-constructors
        NOCOPY(TextureComponent);

        //Destructor
        virtual ~TextureComponent();

        //  //Return texture data
        //  const TextureData& GetTextureDataRef() const;
        //
        //  //Return texture data
        //  TextureData& GetTextureDataRef();
        //
        //  const Font& GetFontRef() const;
        //
        //  Font& GetFontRef();

        //Adds a displayable image
        //Sets the image to be rendered
        //p_name: Name of the file with extension
        //p_images: Number of images in the file, defaults to whole file
        bool AddImage(const std::string& p_name, const Vector2i p_imageCount = Vector2i(0, 0));

        //Set selected image to be rendered
        //p_imageIndex: Index of the image in the sheet
        bool UseImage(const int p_imageIndex);

        //Add font to print characters
        //p_name: Name of the file with extension, currentlty only supports truetype fonts (.ttf)
        bool AddFont(const std::string& p_name);


    private:


        //Data of the read image
        TextureData m_textureData;

        //Data of the Shape that uses this texture
        ShapeData m_shapeData;

        //Data of the read font
        Font m_fontData;

    };

}

#endif