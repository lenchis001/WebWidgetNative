#include "string"

namespace player::web_widget_communication
{
    class WebWidgetCommunicator
    {
    public:
        WebWidgetCommunicator(std::string localPort);

        void initialize();
    private:
        void register_port();
        void send_message();

        std::string _localPort;
    };
}