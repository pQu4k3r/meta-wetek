require conf/license/license-gplv2.inc

PV = "1.0"

SRC_URI = " file://wetek-shutdown.sh"

S = "${WORKDIR}"

INITSCRIPT_NAME = "wetek-shutdown"
INITSCRIPT_PARAMS = "start 39 0 ."

inherit pkgconfig update-rc.d

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/wetek-shutdown.sh ${D}${sysconfdir}/init.d/wetek-shutdown
}

COMPATIBLE_MACHINE = "^(wetekplay|wetekplay2|wetekhub)$"
