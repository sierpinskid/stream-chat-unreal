set dotenv-load := false

# List recipes
default:
  just --list

# Build the entire project
build-project:
    ue4 build --NoPCH -NoSharedPCH -DisableUnity

# Build the StreamChat plugin
build-plugin:
    cd Plugins/StreamChat && ue4 build --NoPCH -NoSharedPCH -DisableUnity

# Run unit tests
test:
    -ue4 test StreamChat

# Convert svg assets to pngs
asset-pipeline:
    for f in SourceArt/*.svg; do echo "$f"; inkscape "$f" -o "${f%.svg}.png"; done