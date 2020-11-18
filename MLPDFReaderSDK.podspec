Pod::Spec.new do |spec|

  spec.name         = "MLPDFReaderSDK"
  spec.version      = "1.1.1"

  spec.summary      = "miLibris iOS PDF Reader SDK"
  spec.description  = <<-DESC
                      MLPDFReaderSDK is the miLibris reading SDK (previously called MLReader). It includes the MLFoundation library allowing to unpack miLibris contents.
                   DESC

  spec.homepage     = "https://github.com/miLibris/ios-milibris-pdf-reader-sdk"
  spec.license      = { :type => 'Copyright', :text => 'Copyright miLibris 2020' }
  spec.author       = { "miLibris" => "support@milibris.com" }

  spec.ios.deployment_target = "10.0"

  spec.source = { :http => "https://seafile.milibris.com/d/b422f2b2a8/files/?p=/MLPDFReaderSDK_v1.1.1.framework.zip&dl=1", :type => "zip" }

  spec.vendored_frameworks = 'MLPDFReaderSDK.framework'

end
