#include "av1_10bit_encoder.h"

const EncoderInfo Av110bitEncoder::encoderInfo = {
    .UUID{0xa6, 0x54, 0x7f, 0x63, 0xec, 0xbc, 0x22, 0x71, 0x15, 0x62, 0xf9, 0x6c, 0x94, 0xb5, 0x87, 0x5e},
    .codecGroup = "AV1",
    .codecName = "VAAPI 10-bit (FFmpeg)",
    .fourCC = 'av01',
    .encoder = "av1_vaapi",
    .hwAcceleration = Vaapi,
    .pixelFormat = AV_PIX_FMT_P010,
    .colorModel = clrNV12,
    .hSubsampling = 2,
    .vSubsampling = 2,
    .qualityModes = CQP | VBR,
    .qp = {1, 25, 63},
    .presets = {{0, "Speed"}, {1, "Balanced"}, {2, "Quality"}},
    .defaultPreset = 1,
};

Av110bitEncoder::Av110bitEncoder() { FFmpegEncoder::encoderInfo = encoderInfo; }

StatusCode Av110bitEncoder::RegisterCodecs(HostListRef* list) { 
    return FFmpegEncoder::RegisterCodecs(list, encoderInfo); 
}

StatusCode Av110bitEncoder::GetEncoderSettings(HostPropertyCollectionRef* values, HostListRef* settingsList) {
    return FFmpegEncoder::GetEncoderSettings(values, settingsList, encoderInfo);
}