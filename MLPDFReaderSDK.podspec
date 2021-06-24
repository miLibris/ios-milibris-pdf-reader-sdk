Pod::Spec.new do |spec|

  spec.name         = "MLPDFReaderSDK"
  spec.version      = "1.3.1"

  spec.summary      = "miLibris iOS PDF Reader SDK"
  spec.description  = <<-DESC
                      MLPDFReaderSDK is the miLibris reading SDK (previously called MLReader). It includes the MLFoundation library allowing to unpack miLibris contents.
                   DESC

  spec.homepage     = "https://github.com/miLibris/ios-milibris-pdf-reader-sdk"
  spec.license      = { :type => 'Copyright', :text => 'Copyright miLibris 2020' }
  spec.author       = { "miLibris" => "support@milibris.com" }

  spec.cocoapods_version = '>= 1.9'

  spec.ios.deployment_target = "11.0"

  spec.source = {
    :http => "https://seafile.milibris.com/d/2ac279fbc3/files/?p=/MLPDFReaderSDK_v1.3.1.xcframework.zip&dl=1",
    :type => "zip",
    :sha256 => '3d1dce143fac4fff44d7926f8faff9b649a6fedcefa11748d263c9f8580b13e5'
  }

  spec.vendored_frameworks = 'MLPDFReaderSDK.xcframework'

  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}

end
