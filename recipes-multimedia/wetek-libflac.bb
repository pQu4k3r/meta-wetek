SUMMARY = "Amlogic audio codecs"

require wetek-lib.inc

S = "${WORKDIR}/libamcodec-openvision/audio_codec/libflac"

DEPENDS = "wetek-libamadec"

EXTRA_OEMAKE = "\
    'CC=${CC}' \
    'CFLAGS=-fPIC -DALSA_OUT -DENABLE_WAIT_FORMAT -I${S}/include -I${S} -I${WORKDIR}/libamcodec-openvision/amadec' \
    'LDFLAGS=-shared -lamadec -lasound' \
"

do_install() {
    install -d ${D}${libdir}
    install -m 0755 ${S}/*.so ${D}${libdir}
}
