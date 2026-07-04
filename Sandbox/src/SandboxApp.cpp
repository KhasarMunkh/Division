#include <Division.h>

class Sandbox : public Division::Application {
public:
    Sandbox() {
        // Initialize your sandbox application here
        
    }

    ~Sandbox() {
        // Clean up resources here
    }
};

Division::Application* Division::CreateApplication() {
    return new Sandbox();
}
