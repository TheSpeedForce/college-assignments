<?php

require_once "../common/dbFetch.php";
require_once "../common/dbconnect.php";

if (session_status() === PHP_SESSION_NONE) {
    session_start();
}

$username = $_SESSION['username'];
$first_initial = $_SESSION['first_initial'];


$studentId = $_POST['select-student'];
$student = fetch(
    $con,
    "
    SELECT 
	student.`id`,
    student.loginInfoId,
    loginInfo.email,
    loginInfo.username,
    loginInfo.fName,
    loginInfo.lName,
    student.termId,
    termType.type as termType,
    term.year as termYear,
    student.advisorId,
    advisor.fName as advisorFN,
    advisor.lName as advisorLN,
    student.programId,
    program.name as programName,
    student.siteId,
    site.name as siteName,
    student.addressId,
    address.line1,
    address.line2,
    address.city,
    address.province,
    address.zip,
    address.country,
    student.`phone`
    FROM `student` 
    INNER JOIN loginInfo ON loginInfo.id=student.loginInfoId
    INNER JOIN term ON term.id=student.termId
    INNER JOIN termType ON termType.id=term.termTypeId
    INNER JOIN advisor ON advisor.id=student.advisorId
    INNER JOIN program ON program.id=student.programId
    INNER JOIN site ON site.id=student.siteId
    INNER JOIN address ON address.id=student.addressId
    WHERE student.id = {$studentId}
    "
)[0];

if(isset($_POST['update'])) {
    var_dump($_POST);
    $q1 = "UPDATE student SET advisorId={$_POST['updateAdvisor']}, siteId={$_POST['updateSite']}, facultySupervisorId={$_POST['updateFSupervisor']}, siteSupervisorId={$_POST['updateSSupervisor']}, termId={$_POST['updateTerm']}, phone={$_POST['updatePhone']} WHERE id={$student['id']}";
    fetch($con, $q1);
    echo "<p>".$q1."</p>";
    $q2 = "UPDATE loginInfo SET fName='{$_POST['updateFName']}', lName='{$_POST['updateLName']}', username='{$_POST['updateUsername']}', email='{$_POST['updateEmail']}' WHERE id={$student['loginInfoId']}";
    fetch($con, $q2);
    echo "<p>".$q2."</p>";
    $q3 = "UPDATE address SET line1='{$_POST['updateLine1']}', line2='{$_POST['updateLine2']}', city='{$_POST['updateCity']}', province='{$_POST['updateProvince']}', zip={$_POST['updateZip']}, country='{$_POST['updateCountry']}' WHERE id={$student['addressId']}";
    fetch($con, $q3);
    echo "<p>".$q3."</p>";
    header('Location: editStudentLanding.php');
}
?>

<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Admin Menu</title>
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
        <a href="#" class = "inactiveLink">Admin Menu</a>
    </span>
    <!-- Wrapper for header interactive elements -->
    <div class="rvt-header__controls">
        <!-- Main inline nav element -->
        <nav class="rvt-header__main-nav" role="navigation">
            <ul>
                <!-- First Navigation !-->
                <li>
                    <a href="../admin/adminMenu.php">Dashboard</a>
                </li>
                <!-- First Navigation !-->
                <li>
                    <a href="../admin/uploadDatasheet.php">Upload/View Datasheet</a>
                </li>

                <!-- Drop down Navigation !-->
                <li>
                    <div class="rvt-dropdown">
                        <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-2" aria-haspopup="true" aria-expanded="false">
                            <span class="rvt-dropdown__toggle-text" aria-current="page"><a aria-current="page">Add New / Edit Exisiting Student</a></span>
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
    <div class="container">
        <h1>Edit Student</h1>
        <form action="editStudent.php" method="post">
            <input type="hidden" name="select-student" value="<?php echo $student['id'] ?>">
            <label>Personal Information</label>
            <table>
                <thead>
                    <th scope='col'>First Name</th>
                    <th scope='col'>Last Name</th>
                    <th scope='col'>Email</th>
                    <th scope='col'>Username</th>
                    <th scope='col'>Phone</th>
                </thead>
                <tbody>
                    <td scope="row">
                        <input name="updateFName" type="text" value="<?php echo $student['fName'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateLName" type="text" value="<?php echo $student['lName'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateEmail" type="text" value="<?php echo $student['email'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateUsername" type="text" value="<?php echo $student['username'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updatePhone" type="text" value="<?php echo $student['phone'] ?>">
                    </td>
                </tbody>
            </table>
            <br>
            <table>
                <caption class="sr-only">Address</caption>
                <thead>
                    <th scope='col'>Line 1</th>
                    <th scope='col'>Line 2</th>
                    <th scope='col'>City</th>
                    <th scope='col'>Province</th>
                    <th scope='col'>Zip</th>
                    <th scope='col'>Country</th>
                </thead>
                <tbody>
                    <td scope="row">
                        <input name="updateLine1" type="text" value="<?php echo $student['line1'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateLine2" type="text" value="<?php echo $student['line2'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateCity" type="text" value="<?php echo $student['city'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateProvince" type="text" value="<?php echo $student['province'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateZip" type="text" value="<?php echo $student['zip'] ?>">
                    </td>
                    <td scope="row">
                        <input name="updateCountry" type="text" value="<?php echo $student['country'] ?>">
                    </td>
                </tbody>
            </table>
            <br>
            <label>Program Information</label>
            <table>
                <thead>
                    <th scope="col">Program</th>
                    <th scope="col">Site</th>
                    <th scope="col">Advisor</th>
                    <th scope="col">Faculty Supervisor</th>
                    <th scope="col">Site Supervisor</th>
                    <th scope="col">Term</th>
                </thead>
                <tbody>
                    <td>
                        <select name="updateProgram">
                            <?php
                            $programs = fetch($con, "SELECT id, name FROM program");
                            foreach ($programs as $program) {
                                echo "<option value='{$program['id']}'>{$program['name']}</option>";
                            }
                            ?>
                        </select>
                    </td>
                    <td>
                        <select name="updateSite">
                            <?php
                            $sites = fetch($con, "SELECT id, name FROM site");
                            foreach ($sites as $site) {
                                echo "<option value='{$site['id']}'>{$site['name']}</option>";
                            }
                            ?>
                        </select>
                    </td>
                    <td>
                        <select name="updateAdvisor">
                            <?php
                            $advisors = fetch($con, "SELECT id, fName, lName FROM advisor");
                            foreach ($advisors as $advisor) {
                                echo "<option value='{$advisor['id']}'>{$advisor['fName']} {$advisor['lName']}</option>";
                            }
                            ?>
                        </select>
                    </td>
                    <td>
                        <select name="updateFSupervisor">
                            <?php
                            $fSupervisors = fetch($con, "SELECT supervisor.id, fName, lName FROM supervisor LEFT JOIN loginInfo ON loginInfo.id=supervisor.loginInfoId WHERE supervisor.roleId = 2");
                            foreach ($fSupervisors as $fSuper) {
                                echo "<option value='{$fSuper['id']}'>{$fSuper['fName']} {$fSuper['lName']}</option>";
                            }
                            ?>
                        </select>
                    </td>
                    <td>
                        <select name="updateSSupervisor">
                            <?php
                            $sSupervisors = fetch($con, "SELECT supervisor.id, fName, lName FROM supervisor LEFT JOIN loginInfo ON loginInfo.id=supervisor.loginInfoId WHERE supervisor.roleId = 1");
                            foreach ($sSupervisors as $sSuper) {
                                echo "<option value='{$sSuper['id']}'>{$sSuper['fName']} {$sSuper['lName']}</option>";
                            }
                            ?>
                        </select>
                    </td>
                    <td>
                        <select name="updateTerm">
                            <?php
                            $terms = fetch($con, "SELECT term.id, termType.type, year FROM term LEFT JOIN termType ON termType.id=term.termTypeId");
                            foreach ($terms as $term) {
                                echo "<option value={$term['id']}>{$term['type']} {$term['year']}</option>";
                            }
                            ?>
                        </select>
                    </td>
                </tbody>
            </table>
            <button class='rvt-button' name='update'>Update</button>
        </form>
    </div>
<?php include "../common/footer.php" ?>
