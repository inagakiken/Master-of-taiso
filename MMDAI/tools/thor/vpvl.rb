require File.dirname(__FILE__) + '/cmake.rb'

module Mmdai

class Vpvl < Thor
  include Build::CMake

  desc "debug", "build libvpvl for debug"
  method_options :flag => :boolean
  def debug
    invoke_build :debug
  end

  desc "release", "build libvpvl for release"
  method_options :flag => :boolean
  def release
    invoke_build :release
  end

  desc "flascc", "build libvpvl for flascc (treats as release)"
  method_options :flag => :boolean
  def flascc
    invoke_build :flascc
  end

  desc "emscripten", "build libvpvl for emscripten (treats as release)"
  method_options :flag => :boolean
  def emscripten
    invoke_build :emscripten
  end

  desc "clean", "delete built libvpvl libraries"
  def clean
    invoke_clean
  end

protected
  def get_build_options(build_type, extra_options)
    return {
      :vpvl_build_qt_renderer => false,
      :vpvl_enable_glsl => false,
      :vpvl_enable_nvidia_cg => false,
      :vpvl_enable_opencl => false,
      :vpvl_enable_project => false,
      :vpvl_link_assimp => false,
      :vpvl_link_qt => false,
      :vpvl_opengl_renderer => false
    }
  end

  def get_directory_name
    return "libvpvl"
  end

end

end
