#include <unistd.h>
#include "zcs/zcs.h"

int main() {
    zcs_init(ZCS_SERVICE_TYPE, 1);
    zcs_attribute_t attribs[] = {
	    { .attr_name = "type", .value = "smartlight"},
	    { .attr_name = "location", .value = "livingroom"},
	    { .attr_name = "make", .value = "toshiba"} };
    zcs_start("speaker-J", attribs, sizeof(attribs)/sizeof(zcs_attribute_t));
    for (int i = 0; i < 1000; i++) {
        zcs_post_ad("light", "on");
        sleep(10);
        zcs_post_ad("light", "off");
        sleep(10);
    }
    zcs_shutdown();
    // zcs_log();
}

