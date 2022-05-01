{
description = "SNES emulator with an extensive set of debugging tools";

inputs = {
  nixpkgs.url = "github:NixOS/nixpkgs";
  flake-utils.url = "github:numtide/flake-utils";

  mesen-s-src.url = "github:NovaSquirrel/Mesen-SX";
  mesen-s-src.flake = false;
  asar-src.url = "github:RPGHacker/asar";
  asar-src.flake = false;
};

outputs = { self,
            nixpkgs,
            flake-utils,
            mesen-s-src,
            asar-src,
... }@inputs:
  flake-utils.lib.eachDefaultSystem (system:
    with import nixpkgs { inherit system; };
    let
      # Executable name
      pname = "";
      # Project version
      version = "";

      asar = stdenv.mkDerivation {
        pname = "asar";
        version = "1.81";

        src = asar-src;

        nativeBuildInputs = [ cmake ];
        configurePhase = "cmake src";
        installPhase = ''
          install -Dm755 asar/asar-standalone $out/bin/asar
        '';
      };
      mesen-s = stdenv.mkDerivation {
        pname = "mesen-s";
        version = "0.4.0";

        src = mesen-s-src;

        nativeBuildInputs = [ clang zip makeWrapper ];
        buildInputs = [ mono6 SDL2 glib gtk2-x11 ];

        preBuild = "make clean";
        makeFlags = [ "LTO=true" ];

        # Adapted from the AUR repo's PKGBUILD
        installPhase = ''
          cat > mesen-s << END
          #!/usr/bin/env sh
          mono $out/opt/mesen-s/mesen-s "\$@"
          END

          install -Dm755 mesen-s $out/bin/mesen-s
          install -Dm755 bin/x64/Release/Mesen-S.exe $out/opt/mesen-s/mesen-s
          install -Dm644 InteropDLL/obj.x64/libMesenSCore.x64.dll $out/lib/libMesenSCore.dll
        '';

        preFixup = ''
          MPATH="$out/lib:${glib.out}/lib:${gtk2-x11}/lib"
          wrapProgram $out/bin/mesen-s --prefix MONO_PATH : "$MPATH" --prefix LD_LIBRARY_PATH : "$MPATH" \
             --prefix PATH : ${lib.makeBinPath [ stdenv.shell mono6 ]}
        '';
       };
    in {
      packages.emulator = mesen-s;

      devShells.default = mkShell {
        packages = [ asar mesen-s ];
      };

      packages.default = stdenv.mkDerivation {
        inherit pname version;
        src = self;
        nativeBuildInputs = [ asar ];
        installPhase = "install -m644 main.sfc $out";
      };
  });
}
