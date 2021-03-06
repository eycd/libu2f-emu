#include <err.h>
#include <stdio.h>

#include "uhid-dev.h"
#include "u2f-dev.h"


/**
** \brief Main function of the program.
**
** \param argc Argc.
** \param argv Argv.
** \return Success: 0.
**         Failure: 1.
*/
int main(int argc, char *argv[])
{
    /* vdev */
    u2f_emu_vdev *vdev = NULL;

    /* Ephemeral */
    if (argc <= 1)
    {
        if (u2f_emu_vdev_new_ephemeral(&vdev) != U2F_EMU_OK)
        {
            warnx("Failed to create a new ephemeral U2F virtual "
                    "emulated device.");
            return 1;
        }
    }
    else
    {
        /* New U2F virtual emulated device */
        if (u2f_emu_vdev_new_from_dir(&vdev, argv[1]) != U2F_EMU_OK)
        {
            /* Log */
            warnx("Failed to create a new U2F virtual emulated device "
                    "from %s", argv[1]);
            return 1;
        }
    }

    /* New USB U2F device */
    u2f_usb_emu_vdev *vdev_usb = NULL;
    if (u2f_dev_new(vdev, &vdev_usb) < 0)
    {
        /* Log */
        warnx("Failed to create a new USB U2F device.");

        /* Release */
        u2f_emu_vdev_free(vdev);
        return 1;
    }
    /* Run */
    int ret = u2f_dev_usb_run(vdev_usb);

    /* Release */
    u2f_dev_free(vdev_usb);
    u2f_emu_vdev_free(vdev);

    return ret;
}
