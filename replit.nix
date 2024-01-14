{ pkgs }: {
    deps = [
      pkgs.gnuplot
      pkgs.ncurses.dev
      pkgs.gd
      pkgs.vimHugeX
      pkgs.raylib
    ];
}
  env = {
    PYTHON_LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
      pkgs.libev
    ];
  };
}