#include <Core\Settings.hpp>

namespace jej
{

    namespace settings
    {

#ifdef _WIN32 //Windows GL attributes

        const EGLint Settings::attributeList[] =
        {
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 16,
            EGL_STENCIL_SIZE, EGL_DONT_CARE,
            EGL_SAMPLE_BUFFERS, 0,
            EGL_NONE
        };


#elif defined __ANDROID__ //Android GL attributes

        const EGLint Settings::attributeList[] =
        {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_NONE
        };

#endif


        std::string Settings::rootPath = "";

        std::string Settings::defaultFragmentShaderFileName = "FragmentShaderTexture.frag";

        std::string Settings::defaultVertexShaderFileName = "VertexShader.vert";

        std::string Settings::defaultErrorTextureName = "error.png";

    }

}

