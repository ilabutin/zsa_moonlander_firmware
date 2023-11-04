#!/bin/bash
docker run -e SKIP_GIT=1 --rm -v $(pwd):/workdir -v $(pwd)/custom:/workdir/qmk_firmware/keyboards/moonlander/keymaps/custom -w /workdir/qmk_firmware  qmkfm/qmk_cli make moonlander:custom
mv $(pwd)/qmk_firmware/moonlander_custom.bin $(pwd)
