Pod::Spec.new do |spec|

  spec.name         = "MLPDFReaderSDK"
  spec.version      = "1.2.0"

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
    :http => "https://seafile.milibris.com/d/115f2510b6/files/?p=/MLPDFReaderSDK_v1.2.0.xcframework.zip&dl=1",
    :type => "zip",
    :sha256 => '41b65d79ac5f1db1e0861fb4b286baf38e1ac52090c394fbfa526b0282609fba'
  }

  spec.vendored_frameworks = 'MLPDFReaderSDK.xcframework'

end
