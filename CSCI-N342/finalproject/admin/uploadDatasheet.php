<?php 

if (session_status() === PHP_SESSION_NONE) {
    session_start();

};
    require_once "../common/readCsv.php";
    require_once "../common/dbFetch.php";
    require_once "../common/dbconnect.php";
    require_once "../common/upload.php";
    $_SESSION['menu'] = 'admin';

    $username = "";
    $first_initial = "";
    
    $username = $_SESSION['username'];
    $first_initial = $_SESSION['first_initial'];

    $update_message = '';

    $filesMoved = NULL;

    
    //var_dump($_FILES);
    $filesMoved = uploadFiles();
    
        
    if($filesMoved != NULL){
        //header('Location: .\adminMenu.php');
        $row = NULL;
        $query = 'SELECT * FROM upload WHERE fileLocation = "'.$filesMoved[0].'" ';
        //echo($query);
        $row = fetch($con, $query);
        //var_dump($row);

        //echo($filesMoved[0]);
        //echo($_SESSION['userId']);
        if($row != NULL){
            $update_message = 'File updated';
        }
        else{
            $query = 'INSERT INTO upload (fileLocation, uploaderId) VALUES (?, ?)';
            $arrayHold = array($filesMoved[0], $_SESSION['userId']);
            fetchArray($con, $query, $arrayHold);
	        $update_message = 'File added';
        }
        $fileLines = readCsv($filesMoved[0]);
        $count = 0;
        foreach($fileLines as $i){
            $emailCheck = NULL;
            $emailCheck = fetch($con, 'SELECT * FROM loginInfo WHERE email = "'.$i[0].'"');
            //var_dump($emailCheck);
            if($emailCheck == NULL){
                $query = 'INSERT INTO loginInfo (email, username, fName, lName, mName, pwdHash) VALUES (?,?,?,?,?,?)';
                $arr = array($i[0], $i[1], $i[2], $i[3], $i[4], "changeme" );
                //echo($query);
                //var_dump($arr);
                fetchArray($con, $query, $arr);
                echo("User Added");
            }
        }
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
    <title>Admin Menu</title>
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
        <a href="uploadDatasheet.php" class = "inactiveLink">Admin Menu</a>
    </span>
    <!-- Wrapper for header interactive elements -->
    <div class="rvt-header__controls">
        <!-- Main inline nav element -->
        <nav class="rvt-header__main-nav" role="navigation">
            <ul>
                <!-- First Navigation !-->
                <li>
                    <a href="adminMenu.php">Dashboard</a>
                </li>
                
                <!-- First Navigation !-->
                <li>
                    <a href="uploadDatasheet.php" aria-current = "page">Upload/View Datasheet</a>
                </li>

                <!-- Drop down Navigation !-->
                
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-2" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text">Add New / Edit Exisiting</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <title>Dropdown icon</title>
                                <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z"
                                />
                            </svg>
                        </button>
                        <div class="rvt-dropdown__menu" id="dropdown-2" aria-hidden="true">
                            <a href="..\add_edit\editAdmin.php">Admin</a>
                            <a href="..\add_edit\editStudentLanding.php">Student</a>
                            <a href="..\add_edit\editSiteSupervisor.php">Site Supervisor</a>
                            <a href="..\add_edit\editFacultySupervisor.php">Faculty Supervisor</a>
                            <a href="..\add_edit\editSite.php">Site</a>
                            <a href="..\add_edit\editSemester.php">Semester</a>
                            <a href="..\add_edit\editCourse.php">Internship Course</a>
                            <a href="#">Site Preference</a>
                            
                        </div>
                    </div>
                </li>
                <!-- Drop down Navigation !-->
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-3" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text">Account Settings</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <title>Dropdown icon</title>
                                <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z"
                                />
                            </svg>
                        </button>
                        <div class="rvt-dropdown__menu" id="dropdown-3" aria-hidden="true">
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
    <main role="main" id="main-content">
    <div>
        <div class="rvt-box">
            <div class="rvt-box__header">
                Upload Datasheet
            </div>
            <div class="rvt-box__body">
            <p>Upload a <b>.csv</b> file that is no larger than 400 KB</p></br>
                <form class="rvt-p-lr-lg" action="uploadDatasheet.php" method="post" enctype="multipart/form-data">
                    <div class="rvt-file" data-upload="file">
                        
                        <input type="file" id="file" name="file" aria-describedby="file-description">
                        <label for="file" class="rvt-button">
                            <span>Upload a file</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <path fill="currentColor" d="M10.41,1H3.5A1.3,1.3,0,0,0,2.2,2.3V13.7A1.3,1.3,0,0,0,3.5,15h9a1.3,1.3,0,0,0,1.3-1.3V4.39ZM11.8,5.21V6H9.25V3h.34ZM4.2,13V3h3V6.75A1.25,1.25,0,0,0,8.5,8h3.3v5Z"/>
                            </svg>
                        </label>
                        <div class="rvt-file__preview" data-file-preview="file" id="file-description">
                            No file selected
                        </div>    
                    </div>
                    </br>
                    <div>
                        <input class="rvt-button" type = "submit" name = "submit" value="Submit">
                    </div>
                </form>
                <p><?php echo($update_message) ?></p>
            </div>
        </div>
        <div class="rvt-box">
            <div class="rvt-box__header">
                View Uploaded Datasheet 
            </div>
            <div class="rvt-box__body"> 
            <?php
                $query = 'SELECT * FROM upload WHERE uploaderId = '.$_SESSION['userId'].' ';
                $row = fetch($con, $query);
                //var_dump($row);
                //var_dump($row);
		        foreach($row as $i){
			        echo("<div>");
				        //echo($i["fileLocation"]);
				        echo('<a href="' .$i['fileLocation'].'">');
                        echo($i['fileLocation']);
                        echo('</a>');
				        echo("</br>");
			        echo("</div");
		}
            ?>
            </div>
        </div>
    </div>
<?php include "../common/footer.php" ?>
