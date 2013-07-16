FILE(REMOVE_RECURSE
  "MMDAI2_automoc.cpp"
  "CMakeFiles/vpvm_translation_target"
  "VPVM_ja.qm"
  "resources/translations/VPVM_ja.ts"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/vpvm_translation_target.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
