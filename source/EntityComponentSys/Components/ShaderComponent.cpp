#include <EntityComponentSys/Components/ShaderComponent.hpp>
#include <EntityComponentSys/Entity/Entity.hpp>

#include <Utility/Messenger.hpp>
#include <Core/Settings.hpp>

#include <EntityComponentSys/Systems/ShaderSystem.hpp>

namespace jej
{
    ShaderComponent::ShaderComponent(Entity* entity, const std::string& p_fragmentShaderFileName, const std::string& p_vertexShaderFileName) :
        Component(entity),
        m_shaderData()
    {
        m_componentType = ComponentType::Shader;

        m_shaderData.fragmentShaderFileName = p_fragmentShaderFileName;
        m_shaderData.vertexShaderFileName = p_vertexShaderFileName;

        ShaderSystem::GetInstance()._initialize(m_shaderData);

    }

    ShaderComponent::~ShaderComponent()
    {

    }

}