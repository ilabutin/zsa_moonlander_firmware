#!/bin/bash
docker run -e SKIP_GIT=1 --rm -v $(pwd):/workdir -w /workdir/qmk_firmware  qmkfm/qmk_cli make moonlander:default
mv $(pwd)/qmk_firmware/moonlander_default.bin $(pwd)