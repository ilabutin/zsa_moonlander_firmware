docker run -e SKIP_GIT=1 --rm -v "${PWD}:/workdir" -v "${PWD}/custom:/workdir/qmk_firmware/keyboards/moonlander/keymaps/custom" -w "/workdir/qmk_firmware" qmkfm/qmk_cli make moonlander:custom
Move-Item -Path "${PWD}\qmk_firmware\moonlander_custom.bin" -Destination $PWD -Force
