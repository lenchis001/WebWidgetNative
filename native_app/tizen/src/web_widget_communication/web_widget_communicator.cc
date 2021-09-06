#include "web_widget_communication/web_widget_communicator.h"
#include "loging/web_logger.h"

#include <message_port.h>

using namespace player::loging;

player::web_widget_communication::WebWidgetCommunicator::WebWidgetCommunicator(std::string localPort)
{
    _localPort = localPort;
}

void player::web_widget_communication::WebWidgetCommunicator::initialize()
{
    register_port();
}

void message_port_cb(int local_port_id, const char *remote_app_id, const char *remote_port,
                     bool trusted_remote_port, bundle *message,
                     void *user_data)
{
    Log("On message received.");
}

void player::web_widget_communication::WebWidgetCommunicator::register_port()
{
    Log("player::web_widget_communication::WebWidgetCommunicator::register_port");

    int port_id = message_port_register_local_port(_localPort.c_str(), message_port_cb, NULL);

    if (port_id < 0)
        Log("Port register error: " + std::to_string(port_id));
    else
        Log("port_id: " + std::to_string(port_id));
}

void player::web_widget_communication::WebWidgetCommunicator::send_message()
{
    Log("WebWidgetCommunicator::send_message");

    bundle *b = nullptr;
    MessagePortResult result = PrepareBundle(message, b);
    if (!result)
    {
        return result;
    }

    message_port_send_message(remote_app_id.c_str(), port_name.c_str(), b);
    
    bundle_free(b);
}