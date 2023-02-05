#include "NAQH.h"

class Sandbox : public NAQH::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
private:
};

NAQH::Application* NAQH::CreateApplication()
{
    return new Sandbox();
}