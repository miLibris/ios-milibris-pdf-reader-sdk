Pod::Spec.new do |spec|

  spec.name         = "MLPDFReaderSDK"
  spec.version      = "1.1.0"

  spec.summary      = "miLibris iOS PDF Reader SDK"
  spec.description  = <<-DESC
                      MLPDFReaderSDK is the miLibris reading SDK (previously called MLReader). It includes the MLFoundation library allowing to unpack miLibris contents.
                   DESC

  spec.homepage     = "https://github.com/miLibris/ios-milibris-pdf-reader-sdk"
  spec.license      = { :type => 'Copyright', :text => 'Copyright miLibris 2020' }
  spec.author       = { "miLibris" => "support@milibris.com" }

  spec.cocoapods_version = '>= 1.9'

  spec.ios.deployment_target = "10.0"

  spec.source = {
    :http => "https://seafile.milibris.com/d/5fabcc8fe9/files/?p=/MLPDFReaderSDK_vspm.xcframework.zip&dl=1",
    :type => "zip",
    :sha256 => 'a7de04ae38f68768ca594d8f577dcfc8fcd8094d5f7a79168eccf77a7baf17f9'
  }

  spec.vendored_frameworks = 'MLPDFReaderSDK.xcframework'

end
