{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "./src/main.cpp"
      ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include_dir\")"
      ]
    }
  ]
}
