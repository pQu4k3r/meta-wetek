KERNELVERSION = "3.14.29"

BOX_BRAND = "wetek"

MTD_BLACK  = "mmcblk0"

PREFERRED_PROVIDER_virtual/kernel = "linux-wetek2"
PREFERRED_VERSION_linux-wetek2 = "${KERNELVERSION}"

# Amlogic defaults
require conf/machine/include/arm/arch-armv8.inc
require conf/machine/include/soc-family.inc


IMAGE_CLASSES += "image_types_wetek"
IMAGE_FSTYPES += "sdcard"
IMAGE_ROOTFS_SIZE = "976562"
IMAGE_EXTRA_SPACE = "0"
IMAGE_OVERHEAD_FACTOR = "1.0"

# Serial console to be used
SERIAL_CONSOLE = "115200 ttyS0"

UBOOT_ENTRYPOINT  = "0x80008000"
UBOOT_LOADADDRESS = "0x80008000"

MACHINE_FEATURES += "bluetooth fb usbhost vfat alsa dvb-c nolcd nogamma HDMI vfdsymbol"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	kernel-module-e2-procfs \
	kernel-modules \
	wetek-dhd-wetekplay2 \
	wetek-mali-wetekplay2 \
	wetek-amlsetfb \
	wetek-shutdown \
	wetek-gst-amlavsink1 \
	wetek-libadpcm \
	wetek-libamplayer \
	wetek-libamavutils \
	wetek-libamadec \
	wetek-libamcodec \
	wetek-libadpcm \
	wetek-libamr \
	wetek-libape \
	wetek-libcook \
	wetek-libfaad \
	wetek-libflac \
	wetek-liblpcm \
	wetek-libmad \
	wetek-libpcm \
	wetek-libraac \
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

KERNEL_IMAGETYPE = "Image"

PREFERRED_PROVIDER_jpeg = "libjpeg-turbo"
PREFERRED_PROVIDER_jpeg-native = "libjpeg-turbo-native"

DVBMEDIASINK_CONFIG = "--with-wmv --with-pcm --with-eac3 --with-dtsdownmix"

CC_append_pn-enigma2 = " -I${STAGING_INCDIR}/amlogic/amcodec -lamcodec"
EXTRA_OECONF_append_pn-enigma2 = " --with-alsa --with-alsacard=hw:0 --with-alsamixer=Master --with-fbdev=/dev/fb2 --with-lcddev=/dev/null --with-amlogic"
DEPENDS_append_pn-enigma2 = " libdvbcsa wetek-libamcodec wetek-libamadec gstreamer1.0 gstreamer1.0-plugins-base"
EXTRA_OECONF_append_pn-tuxtxt-enigma2 = " --with-fbdev=/dev/fb2"
DEPENDS_append_pn-enigma2-plugin-systemplugins-servicemp3 = " wetek-libamcodec "
CC_append_pn-showiframe = " -DHAVE_AMLOGIC -I${STAGING_INCDIR}/amlogic/amcodec -lamcodec -lgstpbutils-1.0 -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0"
DEPENDS_append_pn-showiframe = " wetek-libamcodec gstreamer1.0 gstreamer1.0-libav gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-ugly"


IMAGE_CMD_sdcard_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	mv -f ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.img ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${IMAGE_NAME}.img; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_sdcard.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.img; \
	rm -Rf ${IMAGEDIR}; \
	"

IMAGE_CMD_prepend = "\
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"
