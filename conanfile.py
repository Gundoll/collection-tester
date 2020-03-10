from conans import ConanFile, CMake, tools

class DDSConan(ConanFile):
    name = "collection-tester"
    version = "latest"
    license = "MIT"
    url = "https://github.com/Gundoll/collection-tester.git"
    description = "Collection tester applications"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"

    def source(self):
        self.run("git clone https://github.com/Gundoll/collection-tester.git")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def requirements(self):
        self.requires.add("collection/latest@gundoll/stable", private=False)

    def package(self):
        self.copy("*.h", dst="include", src="include")
