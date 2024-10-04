#include <stdio.h>
#include "pico/stdlib.h"
#include "usb.h"


/* usb_init */
void usb_init(void)
{

}

/* usb_open */
usb_dev_handle *usb_open(struct usb_device *dev)
{
    return 0;
}

/* usb_close */
int	usb_close(usb_dev_handle * dev)
{
    return 0;
}

/* usb_find_busses */
int	usb_find_busses(void)
{
    return 0;
}

/* usb_find_devices */
int	usb_find_devices(void)
{
    return 0;
}

/* usb_get_busses */
struct usb_bus *usb_get_busses(void)
{
    return 0;
}

/* usb_control_msg */
int	usb_control_msg(usb_dev_handle * dev, int requesttype, int request, int value, int index, char *bytes, int size, int timeout)
{
    return 0;
}

/* usb_get_string_simple */
int	usb_get_string_simple(usb_dev_handle * dev, int index, char *buf, size_t buflen)
{
    return 0;
}

/* usb_get_driver_np */
int	usb_get_driver_np(usb_dev_handle * dev, int interface, char *name, int namelen)
{
    return 0;
}

/* usb_detach_kernel_driver_np */
int usb_detach_kernel_driver_np(usb_dev_handle * dev, int interface)
{
    return 0;
}

/* usb_set_configuration */
int	usb_set_configuration(usb_dev_handle * dev, int configuration)
{
    return 0;
}

/* usb_claim_interface */
int	usb_claim_interface(usb_dev_handle * dev, int interface)
{
    return 0;
}

/* usb_release_interface */
int	usb_release_interface(usb_dev_handle * dev, int interface)
{
    return 0;
}

/* usb_bulk_write */
int	usb_bulk_write(usb_dev_handle * dev, int ep, char *bytes, int size, int timeout)
{
    return 0;
}

/* usb_strerror */
const char *usb_strerror(void)
{
    return 0;
}


