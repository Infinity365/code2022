$token = "7nhsb7wf3rknoqnxxcqxabtb2awrat34zibztt3qevag5zrxz3na"

$OrgName = "kigar168"
$ProjectName= "Serviceconnection Teas"
$pat = [System.Convert]::ToBase64String([System.Text.Encoding]::UTF8.GetBytes("PAT:$token"))
$header = @{'Authorization' = "Basic $pat"}
$Witid= 139
$u1='https://dev.azure.com/'+$OrgName+'/'+$ProjectName+'/_apis/wit/workitems/'+$Witid+'?$'
$u2='expand=relations&api-version=5.1'
$URI=$u1+$u2
#Invoke Release REST API
$Call1= Invoke-RestMethod -Method GET -Uri $URI -Headers $header -ContentType 'application/json'
$rel=($Call1.relations.url).Split('/')
$attachmentId = $rel[$rel.count - 1]
Write-Host $attachmentId
$extensionType= ($Call1.relations.attributes.name).Split('.')
$filext=$extensionType[$extensionType.count - 1]
Write-Host $filext
$API2 = 'https://dev.azure.com/'+$OrgName+'/'+$ProjectName+'/_apis/wit/attachments/'+$attachmentId+'?api-version=5.1'
Write-Host " "
Write-Host Final URL is $API2 kindly modify file type to .$filext