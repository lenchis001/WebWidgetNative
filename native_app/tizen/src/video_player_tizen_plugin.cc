#include "video_player_tizen_plugin.h"

#include <app_common.h>
#include <flutter/event_channel.h>
#include <flutter/event_stream_handler_functions.h>
#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>
#include <app_control.h>

#include "flutter_texture_registrar.h"
#include "messages/message.h"
#include "exceptions/video_player_error.h"
#include "exceptions/video_player_options.h"

#include "loging/web_logger.h"
#include "web_widget_communication/web_widget_communicator.h"
#include "constants.h"

using namespace player::messages;
using namespace player::loging;
using namespace player::web_widget_communication;

class VideoPlayerTizenPlugin : public flutter::Plugin, public VideoPlayerApi
{
public:
  static void RegisterWithRegistrar(
      flutter::PluginRegistrar *pluginRegistrar);
  // Creates a plugin that communicates on the given channel.
  VideoPlayerTizenPlugin(flutter::PluginRegistrar *pluginRegistrar);
  virtual ~VideoPlayerTizenPlugin();

  virtual void initialize() override;
  virtual TextureMessage create(const CreateMessage &createMsg) override;
  virtual void dispose(const TextureMessage &textureMsg) override;
  virtual void setLooping(const LoopingMessage &loopingMsg) override;
  virtual void setVolume(const VolumeMessage &volumeMsg) override;
  virtual void setPlaybackSpeed(const PlaybackSpeedMessage &speedMsg) override;
  virtual void play(const TextureMessage &textureMsg) override;
  virtual void pause(const TextureMessage &textureMsg) override;
  virtual PositionMessage position(const TextureMessage &textureMsg) override;
  virtual void seekTo(const PositionMessage &positionMsg) override;
  virtual void setMixWithOthers(
      const MixWithOthersMessage &mixWithOthersMsg) override;

private:
  void disposeAllPlayers();

  flutter::PluginRegistrar *pluginRegistrar_;
  VideoPlayerOptions options_;
  std::unique_ptr<WebWidgetCommunicator> _webWidgetCommunication;
};

// static
void VideoPlayerTizenPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrar *pluginRegistrar)
{
  auto plugin = std::make_unique<VideoPlayerTizenPlugin>(pluginRegistrar);
  pluginRegistrar->AddPlugin(std::move(plugin));
}

VideoPlayerTizenPlugin::VideoPlayerTizenPlugin(
    flutter::PluginRegistrar *pluginRegistrar)
    : pluginRegistrar_(pluginRegistrar)
{
  Log("Inside: VideoPlayerTizenPlugin::VideoPlayerTizenPlugin");

  VideoPlayerApi::setup(pluginRegistrar->messenger(), this);
  _webWidgetCommunication = std::make_unique<WebWidgetCommunicator>("web_widget_local_port");
}

VideoPlayerTizenPlugin::~VideoPlayerTizenPlugin() { disposeAllPlayers(); }

void VideoPlayerTizenPlugin::disposeAllPlayers()
{
  Log("Inside: VideoPlayerTizenPlugin::disposeAllPlayers");
}

void VideoPlayerTizenPlugin::initialize()
{
  Log("Inside: VideoPlayerTizenPlugin::initialize");

  _webWidgetCommunication->initialize();
}

TextureMessage VideoPlayerTizenPlugin::create(const CreateMessage &createMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::create");

  std::string uri;
  if (createMsg.getAsset().empty())
  {
    uri = createMsg.getUri();
  }
  else
  {
    char *resPath = app_get_resource_path();
    if (resPath)
    {
      uri = uri + resPath + "flutter_assets/" + createMsg.getAsset();
      free(resPath);
    }
    else
    {
      throw VideoPlayerError("failed to get resource path", "");
    }
  }

  TextureMessage result;
  result.setTextureId(0);
  return result;
}

void VideoPlayerTizenPlugin::dispose(const TextureMessage &textureMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::dispose");
}

void VideoPlayerTizenPlugin::setLooping(const LoopingMessage &loopingMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::loopingMsg");
}

void VideoPlayerTizenPlugin::setVolume(const VolumeMessage &volumeMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::setVolume");
}

void VideoPlayerTizenPlugin::setPlaybackSpeed(
    const PlaybackSpeedMessage &speedMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::setPlaybackSpeed");
}

void VideoPlayerTizenPlugin::play(const TextureMessage &textureMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::play");
}

void VideoPlayerTizenPlugin::pause(const TextureMessage &textureMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::pause");
}

PositionMessage VideoPlayerTizenPlugin::position(
    const TextureMessage &textureMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::position");

  PositionMessage result;
  result.setTextureId(0);
  result.setPosition(0);
  return result;
}

void VideoPlayerTizenPlugin::seekTo(const PositionMessage &positionMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::seekTo");

  app_control_h app_control;
  app_control_create(&app_control);

  app_control_set_app_id(app_control, WEB_WIDGET_APP_ID);
  app_control_set_launch_mode(app_control, APP_CONTROL_LAUNCH_MODE_GROUP);
  app_control_add_extra_data(app_control, LAUNCH_MODE_PARAMETER_KEY, LAUNCH_MODE_PARAMETER_VALUE);

  auto result = app_control_send_launch_request(app_control, NULL, NULL);
  switch (result)
  {
  case APP_CONTROL_ERROR_NONE:
    Log("APP_CONTROL_ERROR_NONE");
    break;
  case APP_CONTROL_ERROR_PERMISSION_DENIED:
    Log("APP_CONTROL_ERROR_PERMISSION_DENIED");
    break;
  case APP_CONTROL_ERROR_INVALID_PARAMETER:
    Log("APP_CONTROL_ERROR_INVALID_PARAMETER");
    break;
  case APP_CONTROL_ERROR_OUT_OF_MEMORY:
    Log("APP_CONTROL_ERROR_OUT_OF_MEMORY");
    break;
  case APP_CONTROL_ERROR_APP_NOT_FOUND:
    Log("APP_CONTROL_ERROR_APP_NOT_FOUND");
    break;
  case APP_CONTROL_ERROR_LAUNCH_REJECTED:
    Log("APP_CONTROL_ERROR_LAUNCH_REJECTED");
    break;
  case APP_CONTROL_ERROR_LAUNCH_FAILED:
    Log("APP_CONTROL_ERROR_LAUNCH_FAILED");
    break;
  case APP_CONTROL_ERROR_TIMED_OUT:
    Log("APP_CONTROL_ERROR_TIMED_OUT");
    break;
  default:
    Log("default app error");
    break;
  }

  app_control_destroy(app_control);
}

void VideoPlayerTizenPlugin::setMixWithOthers(
    const MixWithOthersMessage &mixWithOthersMsg)
{
  Log("Inside: VideoPlayerTizenPlugin::setMixWithOthers");
  options_.setMixWithOthers(mixWithOthersMsg.getMixWithOthers());
}

void VideoPlayerTizenPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar)
{
  Log("Inside: VideoPlayerTizenPluginRegisterWithRegistrar");
  VideoPlayerTizenPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrar>(registrar));
}
