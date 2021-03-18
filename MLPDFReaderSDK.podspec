Pod::Spec.new do |spec|

  spec.name         = "MLPDFReaderSDK"
  spec.version      = "1.3.0"

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
    :http => "https://seafile.milibris.com/d/22f2a82dbc/files/?p=/MLPDFReaderSDK_v1.3.0.xcframework.zip&dl=1",
    :type => "zip",
    :sha256 => 'c82fbb1cb3772bb3bcf69c22551fcde2eee68291f5e810fcdd781f734441db7f'
  }

  spec.vendored_frameworks = 'MLPDFReaderSDK.xcframework'

  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}

end
