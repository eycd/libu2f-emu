if HAVE_PTHREAD
    GTEST_CPPFLAGS += -DGTEST_HAS_PTHREAD=1
    GTEST_CFLAGS += $(PTHREAD_CFLAGS)
    GTEST_LIBS += $(PTHREAD_LIBS)
else
    GTEST_CPPFLAGS += "-DGTEST_HAS_PTHREAD=0"
endif

AM_CXXFLAGS = $(MY_WARN_CFLAGS) -I${top_srcdir}/src  $(GTEST_CFLAGS)
AM_CPPFLAGS = $(MY_WARN_CFLAGS) -I${top_srcdir}/src $(GTEST_CPPFLAGS)
AM_LDFLAGS = $(GTEST_LDFLAGS) $(GTEST_LIBS)

TESTS = usb message packet
check_PROGRAMS = $(TESTS)

usb_SOURCES = usb.cc
usb_LDADD = $(top_srcdir)/src/libu2f-emu-testing.la

message_SOURCES = message.cc
message_LDADD = $(top_srcdir)/src/libu2f-emu-testing.la

packet_SOURCES = packet.cc
packet_LDADD = $(top_srcdir)/src/libu2f-emu-testing.la
