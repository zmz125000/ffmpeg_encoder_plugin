#include "h265_10bit_encoder.h"

const EncoderInfo H26510bitEncoder::encoderInfo = {
    .UUID{0x3c, 0xfb, 0xec, 0xee, 0xbb, 0x4e, 0x56, 0xcf, 0xf3, 0x38, 0x43, 0x5b, 0xa7, 0x8b, 0xc5, 0x77},
    .codecGroup = "H.265",
    .codecName = "VAAPI 10-bit (FFmpeg)",
    .fourCC = 'hvc1',
    .encoder = "hevc_vaapi",
    .hwAcceleration = Vaapi,
    .pixelFormat = AV_PIX_FMT_P010,
    .colorModel = clrNV12,
    .hSubsampling = 2,
    .vSubsampling = 2,
    .qualityModes = CQP | VBR,
    .qp = {1, 25, 51},
    .presets = {{0, "Speed"}, {1, "Balanced"}, {2, "Quality"}},
    .defaultPreset = 1,
};

H26510bitEncoder::H26510bitEncoder() { FFmpegEncoder::encoderInfo = encoderInfo; }

StatusCode H26510bitEncoder::RegisterCodecs(HostListRef* list) { 
    return FFmpegEncoder::RegisterCodecs(list, encoderInfo); 
}

StatusCode H26510bitEncoder::GetEncoderSettings(HostPropertyCollectionRef* values, HostListRef* settingsList) {
    return FFmpegEncoder::GetEncoderSettings(values, settingsList, encoderInfo);
}