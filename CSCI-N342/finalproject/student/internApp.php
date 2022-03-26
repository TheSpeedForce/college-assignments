<?php 
	
	if (session_status() === PHP_SESSION_NONE) {
	    session_start();
	};
	require_once "../common/dbconnect.php";
	require_once "../common/upload.php";
	
	//var_dump($_FILES);
	
	$_SESSION['menu'] = 'student'; 
	$username = "";
	$first_initial = "";
	
	$username = $_SESSION['username'];
	$first_initial = $_SESSION['first_initial'];
	
	$stmt = $con->prepare('SELECT * FROM program ');
	$stmt->execute();
	$programRow = $stmt->fetchAll(PDO::FETCH_ASSOC);
	
	//foreach($programRow as $i){
	//	echo $i['name'];
	//}
	//echo nl2br("\n");
	$stmt = $con->prepare('SELECT * FROM term ORDER BY id');
	$stmt->execute();
	$termRow = $stmt->fetchAll(PDO::FETCH_ASSOC);
	
	$stmt = $con->prepare('SELECT * FROM termType ORDER BY id');
	$stmt->execute();
	$termTypeRow = $stmt->fetchAll(PDO::FETCH_ASSOC);
	//foreach($termTypeRow as $i){
	//	echo $i['type'];
	//	echo $i['id'];
	//}
	//echo nl2br("\n");
	//foreach($termRow as $i){
	//	echo $i['year'];
	//	foreach($termTypeRow as $j){
	//		if ($i['termTypeId'] == $j['id']){
	//			echo $j['type'];
	//		}
	//	}
	//	
	//}
	
	$stmt = $con->prepare('SELECT * FROM advisor ORDER BY id');
	$stmt->execute();
	$adviseRow = $stmt->fetchAll(PDO::FETCH_ASSOC);
	//foreach($adviseRow as $i){
	//	echo $i['id'];
	//	echo $i['fName'];
	//	echo $i['lName'];
	//}
	
	$stmt = $con->prepare('SELECT * FROM site ORDER BY id');
	$stmt->execute();
	$siteRow = $stmt->fetchAll(PDO::FETCH_ASSOC);
	//foreach($siteRow as $i){
	//	echo $i['id'];
	//	echo $i['name'];
	//}

	
	
	
	$program = '';
	$programLabel = 'Program';
	$pok = 0;
	if(isset($_POST['programselect'])){
		
		$program = $_POST['programselect'];
		$pok = 1;	
	}
	
	
	$placementTerm = '';
	$placementLabel = 'Semester';
	$ptok = 0;
	if(isset($_POST['placement_term'])){
		
		$placementTerm = $_POST['placement_term'];
			
	}
	if($placementTerm == 'default'){
		$placementLabel = '<font color="red">Semester</font>';
	}elseif($placementTerm != ''){
		$ptok = 1;
	}

	$advisor = '';
	$advisorLabel='Advisor';
	$aok = 0;
	if(isset($_POST['advisor'])){
		
		$advisor = $_POST['advisor'];
			
	}
	if($advisor == 'default'){
		$advisorLabel = '<font color="red">Advisor</font>';
	}elseif($advisor != ''){
		$aok = 1;
	}

	$site1Label = 'Site Preference 1';
	$site1 = '';
	$s1ok = 0;
	if(isset($_POST['site1'])){
		
		$site1 = $_POST['site1'];
			
	}
	if($site1 == 'default'){
		$site1Label = '<font color="red">Site Preference 1</font>';

	}elseif($site1 != ''){
		$s1ok = 1;
	}
	
	$site2 = '';
	$site2Label = 'Site Preference 2';
	$s2ok = 0;
	if(isset($_POST['site2'])){
		
		$site2 = $_POST['site2'];
			
	}
	if($site2 == 'default'){
		$site2Label = '<font color="red">Site Preference 2</font>';

	}elseif($site2 != ''){
		$s2ok = 1;
	}


	$site3 = '';
	$site3Label = 'Site Preference 3';
	$s3ok = 0;
	if(isset($_POST['site3'])){
		
		$site3 = $_POST['site3'];
			
	}
	if($site3 == 'default'){
		$site3Label = '<font color="red">Site Preference 3</font>';

	}elseif($site3 != ''){
		$s3ok = 1;
	}
	
	$consid = '';
	if(isset($_POST['consid'])){
		
		$consid = $_POST['consid'];
		
	}
	//var_dump($uploads);
	if($_FILES != NULL){

	}
	if($pok == 1 && $ptok == 1 && $aok == 1 && $s1ok == 1 && $s2ok == 1 && $s3ok == 1 ){
		echo 'Entered Final Round';
		$stmt = $con->prepare('SELECT * FROM student WHERE loginInfoID = ?');
		$stmt->execute(array($_SESSION['userId']));
		$hold = $stmt->fetch(PDO::FETCH_ASSOC);
		//echo($_SESSION['userId']);
		//var_dump($hold);
		//echo($hold['loginInfoId']);
		$query = 'INSERT INTO studentApplication (studentId, courseId, date, semesterId, pref1Id, pref2Id, pref3Id, considerations))';
		$array = array($hold['id'], $program, date("Y-m-d"), $placementTerm, $site1, $site2, $site3, $consid);
		//execute($query, $array);
		echo('Success');
		$_SESSION['POST'] = $array;
		var_dump($_SESSION['POST']);
		$filesMoved = uploadFiles();
		$_SESSION['FILES'] = $filesMoved;
		header("Location: .\confirmIntern.php");
		
	}
	
	

?>
<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link media="all" rel="stylesheet" href="../iudesign/css/rivet.min.css">
    <script src="../iudesign/js/rivet.min.js"></script>
    <!-- Change Title here for each module !-->
    <title>Internship Application</title>
</head>
<body>
<header class="rvt-header" role="banner">
    <a class="rvt-skip-link" href="#main-content">Skip to content</a>
    <!-- Trident -->
    <div class="rvt-header__trident">
        <svg class="rvt-header__trident-logo" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 41 48" aria-hidden="true">
            <title id="iu-logo">Indiana University Logo</title>
            <rect width="41" height="48" fill="#900"/>
            <polygon points="24.59 12.64 24.59 14.98 26.34 14.98 26.34 27.78 22.84 27.78 22.84 10.9 24.59 10.9 24.59 8.57 16.41 8.57 16.41 10.9 18.16 10.9 18.16 27.78 14.66 27.78 14.66 14.98 16.41 14.98 16.41 12.64 8.22 12.64 8.22 14.98 9.97 14.98 9.97 30.03 12.77 33.02 18.16 33.02 18.16 36.52 16.41 36.52 16.41 39.43 24.59 39.43 24.59 36.52 22.84 36.52 22.84 33.02 28 33.02 31.01 30.03 31.01 14.98 32.78 14.98 32.78 12.64 24.59 12.64" fill="#fff"/>
        </svg>
    </div>
    <!-- App title -->
    <span class="rvt-header__title">
        <a href="#" class = "inactiveLink">Student Menu</a>
    </span>
    <!-- Wrapper for header interactive elements -->
    <div class="rvt-header__controls">
        <!-- Main inline nav element -->
        <nav class="rvt-header__main-nav" role="navigation">
            <ul>
				<!-- First Navigation !-->
				<li>
                    <a href="studentMenu.php">Dashboard</a>
                </li>

                <!-- First Navigation !-->
                <li>
                    <a href="internApp.php" aria-current="page">Internship Application</a>
                </li>

                <!-- Second Navigation !-->
                <li>
                    <a href="pdfUpload.php" >Reporting Hours</a>
                </li>

                <!-- Drop down Navigation !-->
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-1" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text">Account Settings</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <title>Dropdown icon</title>
                                <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z"
                                />
                            </svg>
                        </button>
                        <div class="rvt-dropdown__menu" id="dropdown-1" aria-hidden="true">
                            <a href="../common/editProfile.php">Edit Profile</a>
                            <a href="../common/changePassword.php">Change Password</a>
                        </div>
                    </div>
                </li>
                
            </ul>
        </nav>
        <!-- ID menu w/ dropdown -->
        <div class="rvt-header-id">
            <div href="#0" class="rvt-header-id__profile">

                <!-- change these to your username for now !-->
                <span class="rvt-header-id__avatar" aria-hidden="true"><?php print $first_initial ?></span>
                <span class="rvt-header-id__user"><?php print $username ?></span>
            	</div>
            	<a href="../common/logout.php" class="rvt-header-id__log-out">Log out</a>
        </div>
    	</div>
	</header>
	<main>
		<div class="rvt-box__body">
			<form action = "internApp.php" enctype="multipart/form-data" method="post">
				<ul class="rvt-inline-list">
					
						<label for = "program_radio" class="rvt-text-left rvt-text-bold">Program</label>
						<div id = "program_radio" class = "rvt">
						<?php
							foreach($programRow as $i){
								
								$idHold = $i['id'];
								$nameHold = $i['name'];
								echo($idHold);
								echo('<li class="rvt-radio-wrapper">');
								echo('<input type="radio" name="programselect" id="'.$idHold.'" value = "'.$idHold.'"');
								if($idHold == $program){
									echo('checked >');
								}
								else{
									echo('>');
								}
								echo('<label for="'.$idHold.'" class="rvt-m-right-md">'.$nameHold.'</label>');
								echo('</li>');
							
							}
						?>
						</div>
					
					<br>
					<li>
						<label for="placement_term"><?php echo($placementLabel) ?></label>
						<select id="placement_term" name="placement_term">
							<option value="default">Select a Placement Term</option>
							<?php
								foreach($termRow as $i){
									$idHold = $i['id'];
									$yearHold = $i['year'];
									foreach($termTypeRow as $j){
										if($i['termTypeId'] == $j['id']){
											$typeHold = $j['type'];
										}
									}
									echo('<option value ="'.$idHold.'"');
									if($idHold == $placementTerm){
										echo('selected >');
									}
									else{
										echo('>');
									}
									echo($typeHold);
									echo($yearHold.'</option>');
								}
							?>
						</select>
						<br>
						<label for="advisor"><?php echo($advisorLabel) ?></label>
						<select id="advisor" name="advisor">
							<option value="default">Select an Advisor</option>
							<?php
								foreach($adviseRow as $i){
									echo('<option value="'.$i[id].'"');
									if($i[id] == $advisor){
										echo('selected >');
									}else{
										echo('>');
									}
									echo($i['fName']);
									echo(' ');
									echo($i['lName'].'</option>');
								}
							?>
						</select>
						<br>
						<label for="site1"><?php echo($site1Label) ?></label>
						<select id="site1" name="site1">
							<option value="default">Select a Site</option>
							<?php
								foreach($siteRow as $i){
									echo('<option value="'.$i[id].'"');
									if($i['id'] == $site1){
										echo('selected >');
									}else{
										echo('>');
									}
									echo($i['name'].'</option>');
									
								}
							?>
						</select>
						<br>
						<label for="site2"><?php echo($site2Label) ?></label>
						<select id="site2" name="site2">
							<option value="default">Select a Site</option>
							<?php
								foreach($siteRow as $i){
									echo('<option value="'.$i[id].'"');
									if($i['id'] == $site2){
										echo('selected >');
									}else{
										echo('>');
									}
									echo($i['name'].'</option>');
								}
							?>
						</select>
						<br>
						<label for="site3"><?php echo($site3Label) ?></label>
						<select id="site3" name="site3">
							<option value="default">Select a Site</option>
							<?php
								foreach($siteRow as $i){
									echo('<option value="'.$i[id].'"');
									if($i['id'] == $site3){
										echo('selected >');
									}else{
										echo('>');
									}
									echo($i['name'].'</option>');

								}
							?>
						</select>
						<br>
						<br>
						<br>
						<label for="consid">Special Considerations</label>
						<input type="text" id="consid" aria-describedby="consid-note">
						<br>
						<div class="rvt-file" data-upload="resumeUpload">
							<input id="resumeUpload" type="file" name="file1" aria-describedby="file-description1" /><br>
							<label for="resumeUpload" class="rvt-button">
       								 <span>Upload Resume</span>
        								 <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
            									<path fill="currentColor" d="M10.41,1H3.5A1.3,1.3,0,0,0,2.2,2.3V13.7A1.3,1.3,0,0,0,3.5,15h9a1.3,1.3,0,0,0,1.3-1.3V4.39ZM11.8,5.21V6H9.25V3h.34ZM4.2,13V3h3V6.75A1.25,1.25,0,0,0,8.5,8h3.3v5Z"/>
        								</svg>
    							</label>
							<div class="rvt-file__preview" data-file-preview="resumeUpload" id="file-description1">
        								No file selected
    							</div>
						</div>
						<!--<small id=resume-upload-note><?php //echo($pdfUploadSub) ?></small>--><br><br>
						<div class="rvt-file" data-upload="programUpload">
							<input id="programUpload" type="file" name="file2" aria-describedby="file-description2" /><br>
							<label for="programUpload" class="rvt-button">
       								 <span>Upload Study Plan</span>
        								 <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
            									<path fill="currentColor" d="M10.41,1H3.5A1.3,1.3,0,0,0,2.2,2.3V13.7A1.3,1.3,0,0,0,3.5,15h9a1.3,1.3,0,0,0,1.3-1.3V4.39ZM11.8,5.21V6H9.25V3h.34ZM4.2,13V3h3V6.75A1.25,1.25,0,0,0,8.5,8h3.3v5Z"/>
        								</svg>
    							</label>
							<div class="rvt-file__preview" data-file-preview="programUpload" id="file-description2">
        								No file selected
    							</div>

						</div>
						<!--<small id=studies-upload-note><?php //echo($pdfUploadSub) ?></small>-->
					</li>
					<li>
						<button type="submit" class="rvt-button rvt-button--full-width" name="submit" value="submit">Submit</button>
					</li>
				</ul>
				
			</form>
		</div>
	</main>
	

<?php include "../common/footer.php" ?>
