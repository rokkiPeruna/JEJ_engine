//This is Win32's InputManager.hpp source
#include <IO_Manager/Win32/InputManager.hpp>

//

//

//
#include <Windows.h>
#include <iostream>
//

namespace jej
{
    InputManager::InputManager()
    {
        m_keyboardInputQueue.empty();
    }
    //

    InputManager::~InputManager()
    {

    }
    //

    InputManager& InputManager::GetInstance()
    {
        static InputManager iomanager;
        return iomanager;
    }
    //

    void InputManager::_update()
    {
        _handleInputQueues();
    }
    //

    ///////////////////////////////////////////////
    //Private methods

    void InputManager::_handleInputQueues()
    {
        //This is for keyboard events
        while (!m_keyboardInputQueue.empty())
        {
            _isKeyboardKeyPressed(m_keyboardInputQueue.front());
            m_keyboardInputQueue.pop();

        }
    }

    bool InputManager::_isKeyboardKeyPressed(const Keyboard::Key p_key) const
    {
        //Virtual key value
        int vkey = 0;
        switch (p_key)
        {
        default:						vkey = 0;						break;
        case Keyboard::Key::A:          vkey = 'A';						break;
        case Keyboard::Key::B:          vkey = 'B';						break;
        case Keyboard::Key::C:          vkey = 'C';						break;
        case Keyboard::Key::D:          vkey = 'D';						break;
        case Keyboard::Key::E:          vkey = 'E';						break;
        case Keyboard::Key::F:          vkey = 'F';						break;
        case Keyboard::Key::G:          vkey = 'G';						break;
        case Keyboard::Key::H:          vkey = 'H';						break;
        case Keyboard::Key::I:          vkey = 'I';						break;
        case Keyboard::Key::J:          vkey = 'J';						break;
        case Keyboard::Key::K:          vkey = 'K';						break;
        case Keyboard::Key::L:          vkey = 'L';						break;
        case Keyboard::Key::M:          vkey = 'M';						break;
        case Keyboard::Key::N:          vkey = 'N';						break;
        case Keyboard::Key::O:          vkey = 'O';						break;
        case Keyboard::Key::P:          vkey = 'P';						break;
        case Keyboard::Key::Q:          vkey = 'Q';						break;
        case Keyboard::Key::R:          vkey = 'R';						break;
        case Keyboard::Key::S:          vkey = 'S';						break;
        case Keyboard::Key::T:          vkey = 'T';						break;
        case Keyboard::Key::U:          vkey = 'U';						break;
        case Keyboard::Key::V:          vkey = 'V';						break;
        case Keyboard::Key::W:          vkey = 'W';						break;
        case Keyboard::Key::X:          vkey = 'X';						break;
        case Keyboard::Key::Y:          vkey = 'Y';						break;
        case Keyboard::Key::Z:          vkey = 'Z';						break;
        case Keyboard::Key::Num0:       vkey = '0';						break;
        case Keyboard::Key::Num1:       vkey = '1';						break;
        case Keyboard::Key::Num2:       vkey = '2';						break;
        case Keyboard::Key::Num3:       vkey = '3';						break;
        case Keyboard::Key::Num4:       vkey = '4';						break;
        case Keyboard::Key::Num5:       vkey = '5';						break;
        case Keyboard::Key::Num6:       vkey = '6';						break;
        case Keyboard::Key::Num7:       vkey = '7';						break;
        case Keyboard::Key::Num8:       vkey = '8';						break;
        case Keyboard::Key::Num9:       vkey = '9';						break;
        case Keyboard::Key::Escape:     vkey = VK_ESCAPE;				break;
        case Keyboard::Key::LControl:   vkey = VK_LCONTROL;				break;
        case Keyboard::Key::LShift:     vkey = VK_LSHIFT;				break;
        case Keyboard::Key::LAlt:       vkey = VK_LMENU;				break;
        case Keyboard::Key::LSystem:    vkey = VK_LWIN;					break;
        case Keyboard::Key::RControl:   vkey = VK_RCONTROL;				break;
        case Keyboard::Key::RShift:     vkey = VK_RSHIFT;				break;
        case Keyboard::Key::RAlt:       vkey = VK_RMENU;				break;
        case Keyboard::Key::RSystem:    vkey = VK_RWIN;					break;
        case Keyboard::Key::Menu:       vkey = VK_APPS;					break;
        case Keyboard::Key::LBracket:   vkey = VK_OEM_4;				break;
        case Keyboard::Key::RBracket:   vkey = VK_OEM_6;				break;
        case Keyboard::Key::SemiColon:  vkey = VK_OEM_1;				break;
        case Keyboard::Key::Comma:      vkey = VK_OEM_COMMA;			break;
        case Keyboard::Key::Period:     vkey = VK_OEM_PERIOD;			break;
        case Keyboard::Key::Quote:      vkey = VK_OEM_7;				break;
        case Keyboard::Key::Slash:      vkey = VK_OEM_2;				break;
        case Keyboard::Key::BackSlash:  vkey = VK_OEM_5;				break;
        case Keyboard::Key::Tilde:      vkey = VK_OEM_3;				break;
        case Keyboard::Key::Equal:      vkey = VK_OEM_PLUS;				break;
        case Keyboard::Key::Dash:       vkey = VK_OEM_MINUS;			break;
        case Keyboard::Key::Space:      vkey = VK_SPACE;				break;
        case Keyboard::Key::Return:     vkey = VK_RETURN;				break;
        case Keyboard::Key::BackSpace:  vkey = VK_BACK;					break;
        case Keyboard::Key::Tab:        vkey = VK_TAB;					break;
        case Keyboard::Key::PageUp:     vkey = VK_PRIOR;				break;
        case Keyboard::Key::PageDown:   vkey = VK_NEXT;					break;
        case Keyboard::Key::End:        vkey = VK_END;					break;
        case Keyboard::Key::Home:       vkey = VK_HOME;					break;
        case Keyboard::Key::Insert:     vkey = VK_INSERT;				break;
        case Keyboard::Key::Delete:     vkey = VK_DELETE;				break;
        case Keyboard::Key::Add:        vkey = VK_ADD;					break;
        case Keyboard::Key::Subtract:   vkey = VK_SUBTRACT;				break;
        case Keyboard::Key::Multiply:   vkey = VK_MULTIPLY;				break;
        case Keyboard::Key::Divide:     vkey = VK_DIVIDE;				break;
        case Keyboard::Key::Left:       vkey = VK_LEFT;					break;
        case Keyboard::Key::Right:      vkey = VK_RIGHT;				break;
        case Keyboard::Key::Up:         vkey = VK_UP;					break;
        case Keyboard::Key::Down:       vkey = VK_DOWN;					break;
        case Keyboard::Key::Numpad0:    vkey = VK_NUMPAD0;				break;
        case Keyboard::Key::Numpad1:    vkey = VK_NUMPAD1;				break;
        case Keyboard::Key::Numpad2:    vkey = VK_NUMPAD2;				break;
        case Keyboard::Key::Numpad3:    vkey = VK_NUMPAD3;				break;
        case Keyboard::Key::Numpad4:    vkey = VK_NUMPAD4;				break;
        case Keyboard::Key::Numpad5:    vkey = VK_NUMPAD5;				break;
        case Keyboard::Key::Numpad6:    vkey = VK_NUMPAD6;				break;
        case Keyboard::Key::Numpad7:    vkey = VK_NUMPAD7;				break;
        case Keyboard::Key::Numpad8:    vkey = VK_NUMPAD8;				break;
        case Keyboard::Key::Numpad9:    vkey = VK_NUMPAD9;				break;
        case Keyboard::Key::F1:         vkey = VK_F1;					break;
        case Keyboard::Key::F2:         vkey = VK_F2;					break;
        case Keyboard::Key::F3:         vkey = VK_F3;					break;
        case Keyboard::Key::F4:         vkey = VK_F4;					break;
        case Keyboard::Key::F5:         vkey = VK_F5;					break;
        case Keyboard::Key::F6:         vkey = VK_F6;					break;
        case Keyboard::Key::F7:         vkey = VK_F7;					break;
        case Keyboard::Key::F8:         vkey = VK_F8;					break;
        case Keyboard::Key::F9:         vkey = VK_F9;					break;
        case Keyboard::Key::F10:        vkey = VK_F10;					break;
        case Keyboard::Key::F11:        vkey = VK_F11;					break;
        case Keyboard::Key::F12:        vkey = VK_F12;					break;
        case Keyboard::Key::F13:        vkey = VK_F13;					break;
        case Keyboard::Key::F14:        vkey = VK_F14;					break;
        case Keyboard::Key::F15:        vkey = VK_F15;					break;
        case Keyboard::Key::Pause:      vkey = VK_PAUSE;				break;
        }

        //Mask vkey and hexadec 8000, return true if not zero
        return (GetAsyncKeyState(vkey) & 0x8000) != 0;
    }

    bool InputManager::_isMouseButtonPressed(const Mouse::Button) const
    {
        return true;
    }

    jej::Vector2i InputManager::_getMousePosition() const
    {
        POINT point;
        GetCursorPos(&point);
        return(jej::Vector2i(point.x, point.y));
    }

}