KERNELVERSION = "3.14.29"

SOC_FAMILY = "amls905"

require conf/distro/multilib.inc

# Amlogic defaults
require conf/machine/include/wetek-amlogic.inc
require conf/machine/include/arm/arch-armv8.inc
require conf/machine/include/soc-family.inc

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	wetek-dvb-modules-wetekplay2 \
	wetek-dhd-wetekplay2 \
	wetek-mali-wetekplay2 \
	wetek-gst-amlavsink \
	wetek-gst-app \
	wetek-gst-amlavout \
	gst-fluendo-mpegdemux \
	kernel-modules \
	wetek-amlsetfb \
	amremote \
	"

KERNEL_MODULE_AUTOLOAD += "\
	sysfillrect \
	syscopyarea \
	mceusb \
	rc-core \
	mali \
	dhd \
	ch341 \
	rfcomm \
	hidp \
	cfg80211 \
	bluetooth \
	6lowpan-iphc \
	libcrc32c \
	"

module_conf_dhd = "options dhd firmware_path=/lib/firmware/brcm/ nvram_path=/lib/firmware/brcm/"

KERNEL_MODULE_PROBECONF += "dhd"

PREFERRED_PROVIDER_virtual/kernel = "linux-wetek2"
PREFERRED_VERSION_linux-wetek2 = "${KERNELVERSION}"

KERNEL_IMAGETYPE = "Image"

MACHINE_FEATURES += "multilib"

EXTRA_ALSA = "amls905"
