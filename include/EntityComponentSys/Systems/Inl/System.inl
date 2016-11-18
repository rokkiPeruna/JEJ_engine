
template <typename T>
std::vector<std::shared_ptr<T>>& System::getComponentsRef()
{
    return std::get<ComponentHelper<T>::index>(EngineObject::GetInstance().m_systems)->m_components;
}