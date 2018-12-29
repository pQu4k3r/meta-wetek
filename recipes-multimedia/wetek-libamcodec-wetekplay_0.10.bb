require wetek-libamcodec.inc

S = "${WORKDIR}/libamcodec-75f23da/amcodec"

SRC_URI = "https://raw.githubusercontent.com/OpenVisionE2/amlogic-libs/master/libamcodec-75f23da.tar.gz\
           file://add-vformat-hevc.patch \
           file://libamcodec.pc \
"

SRC_URI[md5sum] = "2ff1cbc415271733e1241e8cde0b105e"
SRC_URI[sha256sum] = "e6d1864f53d4390299e1a6a3a11a8bd38fd67d1a99af2e9532f8e40acdfd6c2c"

COMPATIBLE_MACHINE = "wetekplay"