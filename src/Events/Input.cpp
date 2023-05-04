#include "Input.h"

namespace NAQH {
    Input* Input::instance = nullptr;

    Input::Input() {

    }

    Input::~Input() {

    }

    void Input::Create() {
        if(instance != nullptr) {
            return;
        }

        instance = new Input();
    }

    void Input::Start() {

    }

    void Input::Update() {
        
    }
}