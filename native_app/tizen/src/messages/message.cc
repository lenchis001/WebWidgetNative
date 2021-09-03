#include "messages/message.h"

#include <flutter/basic_message_channel.h>
#include <flutter/standard_message_codec.h>

namespace player::messages
{
  long TextureMessage::getTextureId() const { return textureId_; }

  void TextureMessage::setTextureId(long textureId) { textureId_ = textureId; }

  flutter::EncodableValue TextureMessage::toMap()
  {
    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("textureId"),
         flutter::EncodableValue((int64_t)textureId_)}};
    return flutter::EncodableValue(toMapResult);
  }

  TextureMessage TextureMessage::fromMap(const flutter::EncodableValue &value)
  {
    TextureMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &textureId =
          emap[flutter::EncodableValue("textureId")];
      if (std::holds_alternative<int32_t>(textureId) ||
          std::holds_alternative<int64_t>(textureId))
      {
        fromMapResult.setTextureId(textureId.LongValue());
      }
    }
    return fromMapResult;
  }

  std::string CreateMessage::getAsset() const { return asset_; }

  void CreateMessage::setAsset(const std::string &asset) { asset_ = asset; }

  std::string CreateMessage::getUri() const { return uri_; }

  void CreateMessage::setUri(const std::string &uri) { uri_ = uri; }

  std::string CreateMessage::getPackageName() const { return packageName_; }

  void CreateMessage::setPackageName(const std::string &packageName)
  {
    packageName_ = packageName;
  }

  std::string CreateMessage::getFormatHint() const { return formatHint_; }

  void CreateMessage::setFormatHint(const std::string &formatHint)
  {
    formatHint_ = formatHint;
  }

  flutter::EncodableValue CreateMessage::toMap()
  {
    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("asset"), flutter::EncodableValue(asset_)},
        {flutter::EncodableValue("uri"), flutter::EncodableValue(uri_)},
        {flutter::EncodableValue("packageName"),
         flutter::EncodableValue(packageName_)},
        {flutter::EncodableValue("formatHint"),
         flutter::EncodableValue(formatHint_)}};

    return flutter::EncodableValue(toMapResult);
  }

  CreateMessage CreateMessage::fromMap(const flutter::EncodableValue &value)
  {
    CreateMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &asset = emap[flutter::EncodableValue("asset")];
      if (std::holds_alternative<std::string>(asset))
      {
        fromMapResult.setAsset(std::get<std::string>(asset));
      }

      flutter::EncodableValue &uri = emap[flutter::EncodableValue("uri")];
      if (std::holds_alternative<std::string>(uri))
      {
        fromMapResult.setUri(std::get<std::string>(uri));
      }

      flutter::EncodableValue &packageName =
          emap[flutter::EncodableValue("packageName")];
      if (std::holds_alternative<std::string>(packageName))
      {
        fromMapResult.setPackageName(std::get<std::string>(uri));
      }

      flutter::EncodableValue &formatHint =
          emap[flutter::EncodableValue("formatHint")];
      if (std::holds_alternative<std::string>(formatHint))
      {
        fromMapResult.setFormatHint(std::get<std::string>(formatHint));
      }
    }

    return fromMapResult;
  }

  long LoopingMessage::getTextureId() const { return textureId_; }

  void LoopingMessage::setTextureId(long textureId) { textureId_ = textureId; }

  bool LoopingMessage::getIsLooping() const { return isLooping_; }

  void LoopingMessage::setIsLooping(bool isLooping) { isLooping_ = isLooping; }

  flutter::EncodableValue LoopingMessage::toMap()
  {

    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("textureId"),
         flutter::EncodableValue((int64_t)textureId_)},
        {flutter::EncodableValue("isLooping"),
         flutter::EncodableValue(isLooping_)}};

    return flutter::EncodableValue(toMapResult);
  }

  LoopingMessage LoopingMessage::fromMap(const flutter::EncodableValue &value)
  {
    LoopingMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &textureId =
          emap[flutter::EncodableValue("textureId")];
      if (std::holds_alternative<int32_t>(textureId) ||
          std::holds_alternative<int64_t>(textureId))
      {
        fromMapResult.setTextureId(textureId.LongValue());
      }

      flutter::EncodableValue &isLooping =
          emap[flutter::EncodableValue("isLooping")];
      if (std::holds_alternative<bool>(isLooping))
      {
        fromMapResult.setIsLooping(std::get<bool>(isLooping));
      }
    }

    return fromMapResult;
  }

  long VolumeMessage::getTextureId() const { return textureId_; }

  void VolumeMessage::setTextureId(long textureId) { textureId_ = textureId; }

  double VolumeMessage::getVolume() const { return volume_; }

  void VolumeMessage::setVolume(double volume) { volume_ = volume; }

  flutter::EncodableValue VolumeMessage::toMap()
  {

    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("textureId"),
         flutter::EncodableValue((int64_t)textureId_)},
        {flutter::EncodableValue("volume"), flutter::EncodableValue(volume_)}};

    return flutter::EncodableValue(toMapResult);
  }

  VolumeMessage VolumeMessage::fromMap(const flutter::EncodableValue &value)
  {
    VolumeMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &textureId =
          emap[flutter::EncodableValue("textureId")];
      if (std::holds_alternative<int32_t>(textureId) ||
          std::holds_alternative<int64_t>(textureId))
      {
        fromMapResult.setTextureId(textureId.LongValue());
      }

      flutter::EncodableValue &volume = emap[flutter::EncodableValue("volume")];
      if (std::holds_alternative<double>(volume))
      {
        fromMapResult.setVolume(std::get<double>(volume));
      }
    }

    return fromMapResult;
  }

  long PlaybackSpeedMessage::getTextureId() const { return textureId_; }

  void PlaybackSpeedMessage::setTextureId(long textureId)
  {
    textureId_ = textureId;
  }

  double PlaybackSpeedMessage::getSpeed() const { return speed_; }

  void PlaybackSpeedMessage::setSpeed(double speed) { speed_ = speed; }

  flutter::EncodableValue PlaybackSpeedMessage::toMap()
  {

    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("textureId"),
         flutter::EncodableValue((int64_t)textureId_)},
        {flutter::EncodableValue("speed"), flutter::EncodableValue(speed_)}};

    return flutter::EncodableValue(toMapResult);
  }

  PlaybackSpeedMessage PlaybackSpeedMessage::fromMap(
      const flutter::EncodableValue &value)
  {
    PlaybackSpeedMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &textureId =
          emap[flutter::EncodableValue("textureId")];
      if (std::holds_alternative<int32_t>(textureId) ||
          std::holds_alternative<int64_t>(textureId))
      {
        fromMapResult.setTextureId(textureId.LongValue());
      }

      flutter::EncodableValue &speed = emap[flutter::EncodableValue("speed")];
      if (std::holds_alternative<double>(speed))
      {
        fromMapResult.setSpeed(std::get<double>(speed));
      }
    }

    return fromMapResult;
  }

  long PositionMessage::getTextureId() const { return textureId_; }

  void PositionMessage::setTextureId(long textureId) { textureId_ = textureId; }

  long PositionMessage::getPosition() const { return position_; }

  void PositionMessage::setPosition(long position) { position_ = position; }

  flutter::EncodableValue PositionMessage::toMap()
  {

    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("textureId"),
         flutter::EncodableValue((int64_t)textureId_)},
        {flutter::EncodableValue("position"),
         flutter::EncodableValue((int64_t)position_)}};

    return flutter::EncodableValue(toMapResult);
  }

  PositionMessage PositionMessage::fromMap(const flutter::EncodableValue &value)
  {
    PositionMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &textureId =
          emap[flutter::EncodableValue("textureId")];
      if (std::holds_alternative<int32_t>(textureId) ||
          std::holds_alternative<int64_t>(textureId))
      {
        fromMapResult.setTextureId(textureId.LongValue());
      }

      flutter::EncodableValue &position =
          emap[flutter::EncodableValue("position")];
      if (std::holds_alternative<int32_t>(position) ||
          std::holds_alternative<int64_t>(position))
      {
        fromMapResult.setPosition(position.LongValue());
      }
    }

    return fromMapResult;
  }

  bool MixWithOthersMessage::getMixWithOthers() const { return mixWithOthers_; }

  void MixWithOthersMessage::setMixWithOthers(bool mixWithOthers)
  {
    mixWithOthers_ = mixWithOthers;
  }

  flutter::EncodableValue MixWithOthersMessage::toMap()
  {

    flutter::EncodableMap toMapResult = {
        {flutter::EncodableValue("mixWithOthers"),
         flutter::EncodableValue(mixWithOthers_)}};

    return flutter::EncodableValue(toMapResult);
  }

  MixWithOthersMessage MixWithOthersMessage::fromMap(
      const flutter::EncodableValue &value)
  {
    MixWithOthersMessage fromMapResult;
    if (std::holds_alternative<flutter::EncodableMap>(value))
    {
      flutter::EncodableMap emap = std::get<flutter::EncodableMap>(value);
      flutter::EncodableValue &mixWithOthers =
          emap[flutter::EncodableValue("mixWithOthers")];
      if (std::holds_alternative<bool>(mixWithOthers))
      {
        fromMapResult.setMixWithOthers(std::get<bool>(mixWithOthers));
      }
    }

    return fromMapResult;
  }

  void VideoPlayerApi::setup(flutter::BinaryMessenger *binaryMessenger,
                             VideoPlayerApi *api)
  {
    auto initChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.initialize",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      initChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            flutter::EncodableMap wrapped;
            try
            {
              api->initialize();
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto createChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.create",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      createChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            CreateMessage input = CreateMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              TextureMessage output = api->create(input);
              wrapped.emplace(flutter::EncodableValue("result"), output.toMap());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto disposeChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.dispose",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      disposeChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            TextureMessage input = TextureMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->dispose(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto loopingChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.setLooping",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      loopingChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            LoopingMessage input = LoopingMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->setLooping(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto volumeChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.setVolume",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      volumeChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            VolumeMessage input = VolumeMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->setVolume(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto speedChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.setPlaybackSpeed",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      speedChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            PlaybackSpeedMessage input = PlaybackSpeedMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->setPlaybackSpeed(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto playChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.play",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      playChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            TextureMessage input = TextureMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->play(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto positionChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.position",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      positionChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            TextureMessage input = TextureMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              PositionMessage output = api->position(input);
              wrapped.emplace(flutter::EncodableValue("result"), output.toMap());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto seekToChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.seekTo",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      seekToChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            PositionMessage input = PositionMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->seekTo(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto pauseChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.pause",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      pauseChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            TextureMessage input = TextureMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->pause(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }

    auto mixChannel =
        std::make_unique<flutter::BasicMessageChannel<flutter::EncodableValue>>(
            binaryMessenger, "dev.flutter.pigeon.VideoPlayerApi.setMixWithOthers",
            &flutter::StandardMessageCodec::GetInstance());
    if (api != nullptr)
    {
      mixChannel->SetMessageHandler(
          [api](const flutter::EncodableValue &message,
                flutter::MessageReply<flutter::EncodableValue> reply)
          {
            MixWithOthersMessage input = MixWithOthersMessage::fromMap(message);
            flutter::EncodableMap wrapped;
            try
            {
              api->setMixWithOthers(input);
              wrapped.emplace(flutter::EncodableValue("result"),
                              flutter::EncodableValue());
            }
            catch (const VideoPlayerError &e)
            {
              wrapped.emplace(flutter::EncodableValue("error"),
                              VideoPlayerApi::wrapError(e));
            }
            reply(flutter::EncodableValue(wrapped));
          });
    }
  }

  flutter::EncodableValue VideoPlayerApi::wrapError(
      const VideoPlayerError &error)
  {
    flutter::EncodableMap wrapped = {
        {flutter::EncodableValue("message"),
         flutter::EncodableValue(error.getMessage())},
        {flutter::EncodableValue("code"),
         flutter::EncodableValue(error.getCode())},
        {flutter::EncodableValue("details"), flutter::EncodableValue()}};
    return flutter::EncodableValue(wrapped);
  }
}