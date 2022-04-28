{
  description = "Templates for coding SNES roms";

  outputs = { self }: {
    templates.with-asar = {
      description = "A template for programming with the Asar assembler";
      path = ./with-asar;
    };
  };
}
