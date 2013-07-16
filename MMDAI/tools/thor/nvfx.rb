require File.dirname(__FILE__) + '/cmake.rb'
require File.dirname(__FILE__) + '/git.rb'

module Mmdai

class Nvfx < Thor
  include Build::CMake
  include VCS::Git

  desc "debug", "build nvFX for debug"
  method_options :flag => :boolean
  def debug
    checkout
    invoke_build :debug
  end

  desc "release", "build nvFX for release"
  method_options :flag => :boolean
  def release
    checkout
    invoke_build :release, :no_visibility_flags => true
  end

  desc "clean", "delete built nvFX libraries"
  def clean
    invoke_clean
  end

protected
  def get_uri
    "https://github.com/tlorach/nvFX"
  end

  def get_directory_name
    "nvFX-src"
  end

  def get_tag_name
    "master"
  end

  def get_build_options(build_type, extra_options)
    glew_location = "#{get_base_directory}/libvpvl2/vendor/GLEW-1.9.0"
    return {
      :build_samples => false,
      :glew_include_dir => glew_location,
      :glew_source => "#{glew_location}/glew.c",
      :use_cuda => false,
      :use_optix => false,
      :use_opengl => true,
      :use_svcui => false,
      :use_glut => false
    }
  end

end

end
