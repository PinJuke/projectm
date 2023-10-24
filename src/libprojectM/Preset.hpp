#pragma once

#include "Audio/FrameAudioData.hpp"

#include "Renderer/RenderContext.hpp"
#include "Renderer/Texture.hpp"

#include <string>


class Preset
{
public:
    virtual ~Preset() = default;

    /**
     * @brief Initializes additional preset resources.
     * @param renderContext A render context with the initial data.
     */
    virtual void Initialize(const RenderContext& renderContext) = 0;

    /**
     * @brief Renders the preset into the current framebuffer.
     * @param audioData Audio data to be used by the preset.
     * @param renderContext The current render context data.
     */
    virtual void RenderFrame(const libprojectM::Audio::FrameAudioData& audioData,
                             const RenderContext& renderContext) = 0;

    /**
     * @brief Returns a pointer to the current rendering output texture.
     * This pointer (the actual texture) may change from frame to frame, so this pointer should not be stored for use
     * across multiple frames. Instead, a new pointer should be requested whenever needed.
     * @return A pointer to the current output texture of the preset.
     */
    virtual auto OutputTexture() const -> std::shared_ptr<Texture> = 0;

    inline void SetFilename(const std::string& filename)
    {
        m_filename = filename;
    }

    inline const std::string& Filename() const
    {
        return m_filename;
    }

private:
    std::string m_filename;
};
