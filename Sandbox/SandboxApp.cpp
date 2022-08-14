#include <Chimera.h>

class SandboxApp : public Chimera::Application
{
public:
    SandboxApp()
    {

    }

    ~SandboxApp()
    {

    }
};

int main()
{
    SandboxApp* app = new SandboxApp();
    app->Run();
    delete app;
}
