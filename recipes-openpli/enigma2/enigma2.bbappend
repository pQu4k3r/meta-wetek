FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append += "\
	${@bb.utils.contains("MACHINE_FEATURES", "wetek-pli", "file://wetekrcfix.patch file://revert-gamma-changes.patch", "", d)} \
	"
