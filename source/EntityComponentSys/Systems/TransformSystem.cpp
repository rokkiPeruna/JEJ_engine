#include <EntityComponentSys/Systems/TransformSystem.hpp>

namespace jej
{

    std::vector<std::shared_ptr<TransformComponent>> TransformSystem::m_components = {};

    TransformSystem::TransformSystem() :
        System()
    {

    }
    //////////////////////////////////////////

    TransformSystem& TransformSystem::GetInstance()
    {
        static TransformSystem system;
        return system;
    }
    //////////////////////////////////////////

    TransformSystem::~TransformSystem()
    {

    }
    //////////////////////////////////////////

    void TransformSystem::_update(const float deltaTime)
    {
        //Check if changes has occurred so we'll know if vertices needs to be recalculated
        for (auto& itr : m_components)
        {
            if (itr->position.x != itr->previousPosition.x ||
                itr->position.y != itr->previousPosition.y ||
                itr->scale.x != itr->previousScale.x       ||
                itr->scale.y != itr->previousScale.y       ||
                itr->rotation.x != itr->previousRotation.x ||
                itr->rotation.x != itr->previousRotation.y ||
                itr->rotation.x != itr->previousRotation.z )
            {
                itr->hasChanged = true;
            }
            else{itr->hasChanged = false;}
        }
    }
    //////////////////////////////////////////

    bool TransformSystem::_finalize()
    {
        //TODO:
        return true;
    }
    //////////////////////////////////////////

    bool TransformSystem::_initialize()
    {
        //TODO:
        return true;
    }
    //////////////////////////////////////////

}