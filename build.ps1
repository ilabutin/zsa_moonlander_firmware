docker run -e SKIP_GIT=1 --rm -v "${PWD}:/workdir" -w "/workdir/qmk_firmware" qmkfm/qmk_cli make moonlander:default
Move-Item -Path "${PWD}\qmk_firmware\moonlander_default.bin" -Destination $PWD -Force
