#ifndef USB_HEADER
#define USB_HEADER
typedef uint32_t* usb_dev_handle;
#define PATH_MAX 255
#define	USB_RECIP_DEVICE                0x00
#define	USB_RECIP_INTERFACE             0x01
#define	USB_RECIP_ENDPOINT              0x02
#define	USB_RECIP_OTHER                 0x03
#define	USB_TYPE_STANDARD               (0x00 << 5)
#define	USB_TYPE_CLASS                  (0x01 << 5)
#define	USB_TYPE_VENDOR                 (0x02 << 5)
#define	USB_TYPE_RESERVED               (0x03 << 5)
#define	USB_ENDPOINT_IN                 0x80
#define	USB_ENDPOINT_OUT                0x00
#define	USB_REQ_GET_STATUS              0x00
#define	USB_REQ_CLEAR_FEATURE           0x01
#define	USB_REQ_SET_FEATURE             0x03
#define	USB_REQ_SET_ADDRESS             0x05
#define	USB_REQ_GET_DESCRIPTOR          0x06
#define	USB_REQ_SET_DESCRIPTOR          0x07
#define	USB_REQ_GET_CONFIGURATION       0x08
#define	USB_REQ_SET_CONFIGURATION       0x09
#define	USB_REQ_GET_INTERFACE           0x0A
#define	USB_REQ_SET_INTERFACE           0x0B
#define	USB_REQ_SYNCH_FRAME             0x0C


/* USB setup packet */
struct usb_ctrl_setup {
	uint8_t	bRequestType;
	uint8_t	bRequest;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
};

#define	USB_MAXALTSETTING       128	/* Hard limit */
struct usb_interface {
	struct usb_interface_descriptor *altsetting;

	int	num_altsetting;
};

/* USB configuration descriptor */
#define	USB_MAXCONFIG           8
struct usb_config_descriptor {
	uint8_t	bLength;
	uint8_t	bDescriptorType;
	uint16_t wTotalLength;
	uint8_t	bNumInterfaces;
	uint8_t	bConfigurationValue;
	uint8_t	iConfiguration;
	uint8_t	bmAttributes;
	uint8_t	MaxPower;

	struct usb_interface *interface;

	uint8_t *extra;			/* Extra descriptors */
	int	extralen;
};
/* USB device descriptor */
struct usb_device_descriptor {
	uint8_t	bLength;
	uint8_t	bDescriptorType;
	uint16_t bcdUSB;
	uint8_t	bDeviceClass;
	uint8_t	bDeviceSubClass;
	uint8_t	bDeviceProtocol;
	uint8_t	bMaxPacketSize0;
	uint16_t idVendor;
	uint16_t idProduct;
	uint16_t bcdDevice;
	uint8_t	iManufacturer;
	uint8_t	iProduct;
	uint8_t	iSerialNumber;
	uint8_t	bNumConfigurations;
};


/* Data types */
struct usb_device;
struct usb_bus;

/*
 * To maintain compatibility with applications already built with libusb,
 * we must only add entries to the end of this structure. NEVER delete or
 * move members and only change types if you really know what you're doing.
 */
struct usb_device {
	struct usb_device *next;
	struct usb_device *prev;

	char	filename[PATH_MAX + 1];

	struct usb_bus *bus;

	struct usb_device_descriptor descriptor;
	struct usb_config_descriptor *config;

	void   *dev;

	uint8_t	devnum;

	uint8_t	num_children;
	struct usb_device **children;
};

struct usb_bus {
	struct usb_bus *next;
	struct usb_bus *prev;

	char	dirname[PATH_MAX + 1];

	struct usb_device *devices;
	uint32_t location;

	struct usb_device *root_dev;
};

/* usb_init */
void usb_init(void);

/* usb_open */
usb_dev_handle *usb_open(struct usb_device *dev);

/* usb_close */
int	usb_close(usb_dev_handle * dev);

/* usb_find_busses */
int	usb_find_busses(void);

/* usb_find_devices */
int	usb_find_devices(void);

/* usb_get_busses */
struct usb_bus *usb_get_busses(void);

/* usb_control_msg */
int	usb_control_msg(usb_dev_handle * dev, int requesttype, int request, int value, int index, char *bytes, int size, int timeout);

/* usb_get_string_simple */
int	usb_get_string_simple(usb_dev_handle * dev, int index, char *buf, size_t buflen);

/* usb_get_driver_np */
int	usb_get_driver_np(usb_dev_handle * dev, int interface, char *name, int namelen);

/* usb_detach_kernel_driver_np */
int usb_detach_kernel_driver_np(usb_dev_handle * dev, int interface);

/* usb_set_configuration */
int	usb_set_configuration(usb_dev_handle * dev, int configuration);

/* usb_claim_interface */
int	usb_claim_interface(usb_dev_handle * dev, int interface);

/* usb_release_interface */
int	usb_release_interface(usb_dev_handle * dev, int interface);

/* usb_bulk_write */
int	usb_bulk_write(usb_dev_handle * dev, int ep, char *bytes, int size, int timeout);

/* usb_strerror */
const char *usb_strerror(void);

#endif