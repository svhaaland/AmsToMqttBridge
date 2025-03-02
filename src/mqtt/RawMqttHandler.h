#ifndef _RAWMQTTHANDLER_H
#define _RAWMQTTHANDLER_H

#include "AmsMqttHandler.h"

class RawMqttHandler : public AmsMqttHandler {
public:
    RawMqttHandler(MQTTClient* mqtt, const char* topic, bool full) : AmsMqttHandler(mqtt) {
        this->topic = String(topic);
        this->full = full;
    };
    bool publish(AmsData* data, AmsData* previousState);
    bool publishTemperatures(AmsConfiguration*, HwTools*);
    bool publishPrices(EntsoeApi*);
    bool publishSystem(HwTools*);

    static const uint16_t BufferSize = 128;

private:
    String topic;
    bool full;
};
#endif
