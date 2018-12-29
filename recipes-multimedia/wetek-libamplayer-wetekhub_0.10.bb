require wetek-libamplayer.inc

S = "${WORKDIR}/libamcodec-210755d/amplayer"

SRC_URI = "https://raw.githubusercontent.com/OpenVisionE2/amlogic-libs/master/libamcodec-210755d.tar.gz \
           file://libamplayer.pc \
"

SRC_URI[md5sum] = "d2e7dc15302fa64eef54aa67da5f9f34"
SRC_URI[sha256sum] = "79f2ae9c4be27f016314d6ff21f1264c32a73581e5f7c297a7efda6a4cb2df9b"

COMPATIBLE_MACHINE = "wetekhub"