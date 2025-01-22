#!/bin/bash
docker run -e SKIP_GIT=1 --rm -v $(pwd)/qmk_firmware:/qmk_firmware -v $(pwd)/custom:/qmk_firmware/keyboards/zsa/moonlander/keymaps/custom -w /qmk_firmware ghcr.io/qmk/qmk_cli sh -c "pip install appdirs && make zsa/moonlander:custom"
mv $(pwd)/qmk_firmware/zsa_moonlander_custom.bin $(pwd)
