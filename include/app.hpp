#ifndef INCLUDE_APP_HPP_
#define INCLUDE_APP_HPP_

#define ARRAY_SZ(x)         static_cast<size_t>(sizeof(x) / sizeof(x[0]))

typedef struct {
    const char *msg;
} json_msg;

// Sample message set to be transmitted over a socket
const json_msg __msg[] = {
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":0,\"data\":\"{\\\"rgb\\\":0,\\\"illumination\\\":317}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":0,\"data\":\"{\\\"rgb\\\":16777118,\\\"illumination\\\":317}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":0,\"data\":\"{\\\"rgb\\\":16777118,\\\"illumination\\\":436}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":0,\"data\":\"{\\\"rgb\\\":16777118,\\\"illumination\\\":427}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"sensor_ht\",\"sid\":\"xxxxxxxxxxxxxx\",\"short_id\":25698,\"data\":\"{\\\"temperature\\\":\\\"231\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"sensor_ht\",\"sid\":\"xxxxxxxxxxxxxx\",\"short_id\":25698,\"data\":\"{\\\"humidity\\\":\\\"8641\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"report\",\"model\":\"sensor_ht\",\"sid\":\"xxxxxxxxxxxxxx\",\"short_id\":25698,\"data\":\"{\\\"humidity\\\":\\\"8641\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"sensor_ht\",\"sid\":\"xxxxxxxxxxxxxx\",\"short_id\":25698,\"data\":\"{\\\"voltage\\\":2905,\\\"temperature\\\":\\\"231\\\",\\\"humidity\\\":\\\"8641\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}",
        },
        {
                .msg = "{\"cmd\":\"heartbeat\",\"model\":\"gateway\",\"sid\":\"xxxxxxxxxxxx\",\"short_id\":\"0\",\"token\":\"xxxxxxxxxxxxxxxx\",\"data\":\"{\\\"ip\\\":\\\"192.168.201.191\\\"}\"}"
        }
};

// Amount of messages in a queue
const size_t __msg_sz = ARRAY_SZ(__msg);

#endif /* INCLUDE_APP_HPP_ */
