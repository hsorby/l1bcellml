const fs = require('fs');

module.exports = ({github, context}) => {
  
  console.log('=========')
  console.log(github)
  console.log(context)
  console.log(process.env)

  let upload_url = context.payload.release.upload_url
  upload_url = upload_url.split('{').shift()
  
  console.log(process.env.DATA)

  const files = process.env.DATA.split(';')
  console.log(files)  
  for (let index in files) {
    const assetPath = files[index]
    const assetName = assetPath.split('/').pop();
    const contentLength = filePath => fs.statSync(filePath).size;
    const headers = { 'content-type': 'application/octet-stream', 'content-length': contentLength(assetPath) };
    const upload_url_with_name = upload_url + '?name=' + assetName
    github.repos.uploadReleaseAsset({
      url: upload_url_with_name,
      headers,
      file: fs.readFileSync(assetPath)
    });
  }
} 
