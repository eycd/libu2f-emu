MY_WARN_CFLAGS = -Wall -Wextra -Werror -fno-strict-aliasing -Wnested-externs -Wmissing-prototypes -Wstrict-prototypes -Wimplicit-function-declaration -Wold-style-definition -Wall -Wextra -Wundef -Wwrite-strings -Wpointer-arith -Wmissing-declarations -Wredundant-decls -Wno-unused-parameter -Wno-missing-field-initializers -Wformat=2 -Wcast-align -Wformat-nonliteral -Wformat-security -Wsign-compare -Wstrict-aliasing -Wshadow -Winline -Wmissing-format-attribute -Wmissing-noreturn -Winit-self -Wmissing-include-dirs -Wunused-but-set-variable -Warray-bounds -Wreturn-type -Wswitch-enum -Wswitch-default -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference -Wdouble-promotion -Werror -Wno-suggest-attribute=format -Wno-error=unused-parameter -Wno-error=missing-field-initializers

AM_CFLAGS = $(MY_WARN_CFLAGS) -I${top_srcdir}/src
AM_CPPFLAGS = -D_GNU_SOURCE
AM_LDFLAGS = $(OPENSSL_LIBS)

lib_LTLIBRARIES = libu2f-emu.la
u2f_emu_includedir = $(includedir)/u2f-emu
u2f_emu_include_HEADERS = u2f-emu.h u2f-emu-types.h

# General
libu2f_emu_la_SOURCES = u2f-emu-types.h u2f-vdev.h
libu2f_emu_la_SOURCES += u2f-emu.c u2f-emu.h
libu2f_emu_la_SOURCES += counter.c counter.h
libu2f_emu_la_SOURCES += crypto.c crypto.h
libu2f_emu_la_SOURCES += transport.c transport.h
libu2f_emu_la_SOURCES += payload.c payload.h
libu2f_emu_la_SOURCES += error.c utils.c
# USB
libu2f_emu_la_SOURCES += usb/usb.c usb/usb.h
libu2f_emu_la_SOURCES += usb/transaction.c usb/transaction.h
libu2f_emu_la_SOURCES += usb/message.c usb/message.h
libu2f_emu_la_SOURCES += usb/cmd.c usb/cmd.h
libu2f_emu_la_SOURCES += usb/packet.c usb/packet.h
# RAW
libu2f_emu_la_SOURCES += raw/raw.c raw/raw.h
libu2f_emu_la_SOURCES += raw/authenticate.c
libu2f_emu_la_SOURCES += raw/register.c
# APDU
libu2f_emu_la_SOURCES += apdu/apdu.c apdu/apdu.h
# MISC
libu2f_emu_la_SOURCES += u2f-emu.pc.in u2f-emu.map

# Libs
libu2f_emu_la_LIBADD = $(OPENSSL_LIBS)

# Lib info
libu2f_emu_la_LDFLAGS = -version-info $(SO_VERSION)
libu2f_emu_la_LDFLAGS += -Wl,--version-script=$(srcdir)/u2f-emu.map

# Same lib with symbol visibility set for testing
lib_LTLIBRARIES += libu2f-emu-testing.la
libu2f_emu_testing_la_SOURCES = $(libu2f_emu_la_SOURCES)
libu2f_emu_testing_la_LIBADD = $(libu2f_emu_la_LIBADD)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = u2f-emu.pc
