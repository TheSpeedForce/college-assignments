<?php

require_once "../common/dbconnect.php";
require_once "../common/dbFetch.php";
require_once "../common/upload.php";
require_once "../models/hours.php";
require_once "../models/hoursReport.php";

if (session_status() === PHP_SESSION_NONE) {
    session_start();
}

$_SESSION['menu'] = 'student';
$username = "";
$first_initial = "";

$username = $_SESSION['username'];
$first_initial = $_SESSION['first_initial'];

$semQueryStr = "SELECT term.id, termType.type, term.year FROM term INNER JOIN termType ON term.termTypeId=termType.id;";
$semQuery = $con->prepare($semQueryStr);
$semQuery->execute();

$siteQueryStr = "SELECT site.id, site.name FROM site";
$siteQuery = $con->prepare($siteQueryStr);
$siteQuery->execute();

$expQueryStr = "SELECT id, program.name FROM program";
$expQuery = $con->prepare($expQueryStr);
$expQuery->execute();

$hrsTypesQueryStr = "SELECT id, hoursFormTypes.type FROM hoursFormTypes;";
$hrsTypesQuery = $con->prepare($hrsTypesQueryStr);
$hrsTypesQuery->execute();

$agesQueryStr = "SELECT id, ageGroup.label FROM ageGroup;";
$agesQuery = $con->prepare($agesQueryStr);
$agesQuery->execute();

$activityHoursFormTypesQueryStr = "SELECT id, activityHoursFormType.formType from activityHoursFormType;";
$activityHoursFormTypesQuery = $con->prepare($activityHoursFormTypesQueryStr);
$activityHoursFormTypesQuery->execute();

$activityTypesQueryStr = "SELECT activityType.id, activityType.type, activityHoursFormType.formType from activityType INNER JOIN activityHoursFormType ON activityType.formId=activityHoursFormType.id;";
$activityTypesQuery = $con->prepare($activityTypesQueryStr);
$activityTypesQuery->execute();

$siteSupervisorQueryStr = "SELECT supervisor.id, loginInfo.fName, loginInfo.lName FROM supervisor INNER JOIN loginInfo ON supervisor.loginInfoId=loginInfo.Id AND supervisor.roleId = 1;";
$siteSupervisorQuery = $con->prepare($siteSupervisorQueryStr);
$siteSupervisorQuery->execute();

$facultySupervisorQueryStr = "SELECT supervisor.id, loginInfo.fName, loginInfo.lName FROM supervisor INNER JOIN loginInfo ON supervisor.loginInfoId=loginInfo.Id AND supervisor.roleId = 2;";
$facultySupervisorQuery = $con->prepare($facultySupervisorQueryStr);
$facultySupervisorQuery->execute();

$experienceTypes = $expQuery->fetchAll(PDO::FETCH_ASSOC);
$semesters = $semQuery->fetchAll(PDO::FETCH_ASSOC);
$locations = $siteQuery->fetchAll(PDO::FETCH_ASSOC);
$hrsTypes = $hrsTypesQuery->fetchAll(PDO::FETCH_ASSOC);
$ages = $agesQuery->fetchAll(PDO::FETCH_ASSOC);
$activityHoursFormTypes = $activityHoursFormTypesQuery->fetchAll(PDO::FETCH_ASSOC);
$activityTypes = $activityTypesQuery->fetchAll(PDO::FETCH_ASSOC);
$siteSupervisor = $siteSupervisorQuery->fetchAll(PDO::FETCH_ASSOC);
$facultySupervisor = $facultySupervisorQuery->fetchAll(PDO::FETCH_ASSOC);
$countFormTypes = fetch($con, "SELECT * FROM countFormType;");
$countTypes = fetch($con, "SELECT * FROM countType;");

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $filesMoved = uploadFiles();

    #echo "POST:" . var_dump($_POST);
    $hours = new Hours();
    foreach ($hrsTypes as $type) {
        if ($type["id"] == 1) {
            fetch($con, "INSERT INTO hoursForm (typeId) values ({$type["id"]});");
            $indHoursId = $con->lastInsertId();
            $hours->ageDirectContactId = $indHoursId;

            fetch($con, "INSERT INTO hoursForm (typeId) values (7);");
            $groupHoursId = $con->lastInsertId();
            $hours->groupDirectContactId = $groupHoursId;

            foreach ($ages as $age) {
                $key = preg_replace('/\s+/', '_', $type["type"]);
                $indHours = $_POST[$key][$age["label"]]["indHrs"];
                $indClients = $_POST[$key][$age["label"]]["indNumClients"];
                $groupHours = $_POST[$key][$age["label"]]["groupHrs"];
                $groupClients = $_POST[$key][$age["label"]]["groupNumClients"];

                fetch($con, "INSERT INTO clientHours (hours, numClients, ageGroupId, hoursFormId) values ({$indHours}, {$indClients}, {$age["id"]}, {$indHoursId})");
                fetch($con, "INSERT INTO clientHours (hours, numClients, ageGroupId, hoursFormId) values ({$groupHours}, {$groupClients}, {$age["id"]}, {$groupHoursId})");
            }
        } else if ($type["id"] != 7) {
            $key = preg_replace('/\s+/', '_', $type["type"]);
            fetch($con, "INSERT INTO hoursForm (typeId) values ({$type["id"]});");
            $hoursFormId = $con->lastInsertId();
            $hours->$key = $hoursFormId;

            foreach ($ages as $age) {
                $numHours = $_POST[$key][$age["label"]]["clientHours"];
                $numClients = $_POST[$key][$age["label"]]["numClients"];
                fetch($con, "INSERT INTO clientHours (hours, numClients, ageGroupId, hoursFormId) values ({$numHours}, {$numClients}, {$age["id"]}, {$hoursFormId})");
            }
        }
    }
    foreach ($activityHoursFormTypes as $type) {
        $key = preg_replace('/(\s+|\/+)+/', '_', $type["formType"]);
        fetch($con, "INSERT INTO activityHoursForm (typeId) values ({$type['id']})");
        $activityHoursId = $con->lastInsertId();
        $hours->$key = $activityHoursId;

        foreach ($activityTypes as $activity) {
            if ($activity['formType'] == $type['formType']) {
                $activityKey = preg_replace('/(\s+|\/+)+/', '_', $activity['type']);
                $activityHours = $_POST[$key][$activityKey];
                fetch($con, "INSERT INTO activityHours (hoursFormId, typeId, hours) values ({$activityHoursId}, {$activity['id']}, {$activityHours});");
            }
        }
    }
    foreach ($countFormTypes as $countFormType) {
        $formTypeKey = preg_replace('/(\s+|\/+|-+)+/', '_', "{$countFormType['type']}");
        fetch($con, "INSERT INTO clientCountForm (typeId) values ({$countFormType['id']})");
        $countFormId = $con->lastInsertId();
        $hours->$formTypeKey = $countFormId;

        foreach ($countTypes as $countType) {
            if ($countType['countForm'] == $countFormType['id']) {
                $countTypeKey = preg_replace('/(\s+|\/+|-+)+/', '_', "{$countType['type']}");
                $numClients = $_POST[$formTypeKey][$countTypeKey];
                fetch($con, "INSERT INTO clientCount (countForm, typeId, numClients) values ({$countFormId}, {$countType['id']}, {$numClients});");
            }
        }
    }

    $hoursReport = new HoursReport();
    $hours->submit($con);
    $hoursId = $con->lastInsertId();

    $hoursReport->hours = $hoursId;
    $studentId = fetch($con, "SELECT student.id FROM student INNER JOIN loginInfo ON student.loginInfoId=loginInfo.id WHERE loginInfo.username='{$_SESSION['username']}'")[0]['id'];
    $studentLoginId = fetch($con, "SELECT id FROM loginInfo WHERE username = '{$_SESSION['username']}'");


    $liabilityPath = $filesMoved[0];
    $experiencePath = $filesMoved[1];

    $liabilityId = NULL;
    $checkLiability = fetch($con, "SELECT * FROM upload WHERE fileLocation = '{$liabilityPath}'");
    if ($checkLiability == NULL) {
        fetch($con, "INSERT INTO upload (fileLocation, uploaderId) VALUES ('{$liabilityPath}', {$studentLoginId[0]['id']})");
        $liabilityId = $con->lastInsertId();
    } else {
        $liabilityId = $checkLiability[0]['id'];
    }

    $experienceId = NULL;
    $checkExperience = fetch($con, "SELECT * FROM upload WHERE fileLocation = '{$experiencePath}'");
    if ($checkExperience == NULL) {
        fetch($con, "INSERT INTO upload (fileLocation, uploaderId) VALUES ('{$experiencePath}', {$studentLoginId[0]['id']})");
        $experienceId = $con->lastInsertId();
    } else {
        $experienceId = $checkExperience[0]['id'];
    }

    $hoursReport->studentId = $studentId;
    $hoursReport->liabilityFile = $liabilityId;
    $hoursReport->experienceFile = $experienceId;
    $hoursReport->startDate = $_POST['beginDate'];
    $hoursReport->endDate = $_POST['endDate'];
    $hoursReport->semesterId = $_POST['select-semester'];
    $hoursReport->siteId = $_POST['location'];
    $hoursReport->programId = $_POST['select-experience'];
    $hoursReport->siteSuperId = $_POST['siteSuper'];
    $hoursReport->facSuperId = $_POST['facultySuper'];
    $hoursReport->submit($con);
}

?>

<!DOCTYPE html>
<html>
<html lang="en-US">

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link media="all" rel="stylesheet" href="../iudesign/css/rivet.min.css">
    <script src="../iudesign/js/rivet.min.js"></script>
    <!-- Change Title here for each module !-->
    <title>Student Menu</title>
</head>

<body>
    <header class="rvt-header" role="banner">
        <a class="rvt-skip-link" href="#main-content">Skip to content</a>
        <!-- Trident -->
        <div class="rvt-header__trident">
            <svg class="rvt-header__trident-logo" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 41 48" aria-hidden="true">
                <title id="iu-logo">Indiana University Logo</title>
                <rect width="41" height="48" fill="#900" />
                <polygon points="24.59 12.64 24.59 14.98 26.34 14.98 26.34 27.78 22.84 27.78 22.84 10.9 24.59 10.9 24.59 8.57 16.41 8.57 16.41 10.9 18.16 10.9 18.16 27.78 14.66 27.78 14.66 14.98 16.41 14.98 16.41 12.64 8.22 12.64 8.22 14.98 9.97 14.98 9.97 30.03 12.77 33.02 18.16 33.02 18.16 36.52 16.41 36.52 16.41 39.43 24.59 39.43 24.59 36.52 22.84 36.52 22.84 33.02 28 33.02 31.01 30.03 31.01 14.98 32.78 14.98 32.78 12.64 24.59 12.64" fill="#fff" />
            </svg>
        </div>
        <!-- App title -->
        <span class="rvt-header__title">
            <a href="#" class="inactiveLink">Student Menu</a>
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
                        <a href="internApp.php">Internship Application</a>
                    </li>

                    <!-- Second Navigation !-->
                    <li>
                        <a href="pdfUpload.php" aria-current="page">Reporting Hours</a>
                    </li>

                    <!-- Drop down Navigation !-->
                    <li>
                        <div class="rvt-dropdown">
                            <button type="button" class="rvt-dropdown__toggle" data-dropdown-toggle="dropdown-1" aria-haspopup="true" aria-expanded="false">
                                <span class="rvt-dropdown__toggle-text">Account Settings</span>
                                <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                    <title>Dropdown icon</title>
                                    <path fill="currentColor" d="M8,12.46a2,2,0,0,1-1.52-.7L1.24,5.65a1,1,0,1,1,1.52-1.3L8,10.46l5.24-6.11a1,1,0,0,1,1.52,1.3L9.52,11.76A2,2,0,0,1,8,12.46Z" />
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
    <main role="main" id="main-content">
        <div class="rvt-container rvt-container--center rvt-container--junior rvt-m-bottom-xxl">
            <form action="hoursForm.php" method="post" enctype="multipart/form-data">
                <div class="col-sm">
                    <h3 class="rvt-text-bold">Hours Report</h3>

                    <label>*First Name</label>
                    <input type="text" id="" name="fName" value="<?php echo $_SESSION['fName'] ?>" disabled><br>

                    <label>*Last Name</label>
                    <input type="text" id="" name="lName" value="<?php echo $_SESSION['lName'] ?>" disabled><br>

                    <label>*Email</label>
                    <input type="text" id="" name="email" value="<?php echo $_SESSION['email'] ?>" disabled><br>

                    <?php

                        
                    ?>

                    <div class="rvt-file" data-upload="liabilityFile">
                        <input type="file" name="liabilityFile" id="liabilityFile" aria-describedby="liabilityFile" required="required">
                        <label for="liabilityFile" class="rvt-button rvt-button--secondary">
                            <span>Liability Insurance</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <path fill="currentColor" d="M10.41,1H3.5A1.3,1.3,0,0,0,2.2,2.3V13.7A1.3,1.3,0,0,0,3.5,15h9a1.3,1.3,0,0,0,1.3-1.3V4.39ZM11.8,5.21V6H9.25V3h.34ZM4.2,13V3h3V6.75A1.25,1.25,0,0,0,8.5,8h3.3v5Z" />
                            </svg>
                        </label>
                        <div class="rvt-file__preview" data-file-preview="liabilityFIle" id="liabilityFile">
                            No file selected
                        </div>
                    </div>

                    <label for="select-experience">Program</label>
                    <select onchange="experience()" id="select-experience" name="select-experience">
                        <?php
                        foreach ($experienceTypes as $exp) {
                            echo "<option value=\"{$exp['id']}\">{$exp['name']}</option>";
                        }
                        ?>
                    </select><br>

                    <div class="rvt-file" data-upload="experienceFile">
                        <input type="file" name="experienceFile" id="experienceFile" aria-describedby="experienceFile" required="required">
                        <label for="experienceFile" class="rvt-button rvt-button--secondary">
                            <span>Experience Agreement File</span>
                            <svg aria-hidden="true" xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16">
                                <path fill="currentColor" d="M10.41,1H3.5A1.3,1.3,0,0,0,2.2,2.3V13.7A1.3,1.3,0,0,0,3.5,15h9a1.3,1.3,0,0,0,1.3-1.3V4.39ZM11.8,5.21V6H9.25V3h.34ZM4.2,13V3h3V6.75A1.25,1.25,0,0,0,8.5,8h3.3v5Z" />
                            </svg>
                        </label>
                        <div class="rvt-file__preview" data-file-preview="experienceFile" id="experienceFile">
                            No file selected
                        </div>
                    </div>
                </div>
                <div class="col-sm">
                    <h3>Shift Details</h3>

                    <label>*Beginning Date</label>
                    <input type="date" id="" name="beginDate" required="required"><br>

                    <label>*End Date</label>
                    <input type="date" id="" name="endDate" required="required"><br>

                    <label for="select-semester">Semester</label><br>
                    <select id="select-semester" name="select-semester"><br>
                        <?php
                        foreach ($semesters as $sem) {
                            echo "<option value=\"{$sem['id']}\">{$sem['type']}, {$sem['year']}</option>";
                        }
                        ?>
                    </select>

                    <label for="select-location">Location</label>
                    <select id="select-location" name="location">
                        <?php
                        foreach ($locations as $loc) {
                            echo "<option value=\"{$loc['id']}\">{$loc['name']}</option>";
                        }
                        ?>
                    </select>

                    <label for="select-siteSuper">Site Supervisor</label>
                    <select id="select-siteSuper" name="siteSuper">
                        <?php
                        foreach ($siteSupervisor as $sSup) {
                            echo "<option value=\"{$sSup['id']}\">{$sSup['fName']} {$sSup['lName']}</option>";
                        }
                        ?>
                    </select>

                    <label for="select-facultySuper">Faculty Supervisor</label>
                    <select id="select-facultySuper" name="facultySuper">
                        <?php
                        foreach ($facultySupervisor as $fSup) {
                            echo "<option value=\"{$fSup['id']}\">{$fSup['fName']} {$fSup['lName']}</option>";
                        }
                        ?>
                    </select>

                    <div id="hours-report">
                        <?php
                        foreach ($hrsTypes as $type) {
                            if ($type['id'] != '1' && $type['id'] != '7') {
                                echo "<label>{$type['type']}</label>";
                                echo "<table class=\"rvt-table-stripes\">
                                    <thead>
                                        <tr>
                                            <th scope=\"col\">Age Group</th>
                                            <th scope=\"col\">Client Hours</th>
                                            <th scope=\"col\"># Clients</th>
                                        </tr>
                                    </thead>
                                    <tbody>";
                                foreach ($ages as $age) {
                                    echo "<tr>
                                        <td>{$age['label']}</td>
                                        <td><input type=\"text\" name=\"{$type['type']}[{$age['label']}][clientHours]\" value=\"0\"></td>
                                        <td><input type=\"text\" name=\"{$type['type']}[{$age['label']}][numClients]\" value=\"0\"></td>
                                    </tr>";
                                }
                                echo "</tbody></table>";
                            } else if ($type['id'] == '1') {
                                echo "<label>{$type['type']}</label>";
                                echo "<table class=\"rvt-table-stripes\">
                                    <thead>
                                        <tr>
                                            <th scope=\"col\">Age Group</th>
                                            <th scope=\"col\">Individual Student Counseling Client Hours</th>
                                            <th scope=\"col\">Individual Student Counseling # Clients</th>
                                            <th scope=\"col\">Group Student Counseling Client Hours</th>
                                            <th scope=\"col\">Group Student Counseling # Clients</th>
                                        </tr>
                                    </thead>
                                    <tbody>";
                                foreach ($ages as $age) {
                                    echo "<tr>
                                            <td>{$age['label']}</td>
                                            <td><input type=\"text\" name=\"{$type['type']}[{$age['label']}][indHrs]\" value=\"0\"></td>
                                            <td><input type=\"text\" name=\"{$type['type']}[{$age['label']}][indNumClients]\" value=\"0\"></td>
                                            <td><input type=\"text\" name=\"{$type['type']}[{$age['label']}][groupHrs]\" value=\"0\"></td>
                                            <td><input type=\"text\" name=\"{$type['type']}[{$age['label']}][groupNumClients]\" value=\"0\"></td>
                                        </tr>";
                                }
                                echo "</tbody></table>";
                            }
                        }
                        foreach ($countFormTypes as $countFormType) {
                            echo "<label>{$countFormType['type']}</label>";
                            echo "<table class=\"rvt-table-stripes\">
                                    <thead>
                                        <tr>
                                            <th></th>
                                            <th scope=\"col\"># Clients</th>
                                        </tr>
                                    </thead>
                                    <tbody>";
                            foreach ($countTypes as $countType) {
                                if ($countType['countForm'] == $countFormType['id']) {
                                    $formKey = preg_replace('/(\s+|\/+|-+)+/', '_', "{$countFormType['type']}[{$countType['type']}]");
                                    echo "<tr>
                                            <td>{$countType['type']}</td>
                                            <td><input type=\"text\" name=\"{$formKey}][numClients]\" value=\"0\"></td>
                                        </tr>";
                                }
                            }
                            echo "</tbody></table>";
                        }
                        ?>
                    </div>
                    <div id="g647-tables">
                        <?php
                        foreach ($activityHoursFormTypes as $formType) {
                            echo "<label>{$formType['formType']}</label>";
                            echo "<table class=\"rvt-table-stripes\">
                                    <thead>
                                        <tr>
                                            <th scope=\"col\">Activities</th>
                                            <th scope=\"col\">Hours</th>
                                        </tr>
                                    </thead>
                                    <tbody>";
                            foreach ($activityTypes as $actType) {
                                if ($actType['formType'] == $formType['formType']) {
                                    $name = preg_replace('/(\s+|\/+)+/', '_', "{$formType['formType']}[{$actType['type']}]");
                                    echo "
                                            <tr>
                                                <td>{$actType['type']}</td>
                                                <td><input type=\"text\" name=\"{$name}\" value=\"0\"></td>
                                            </tr>";
                                }
                            }
                            echo "</tbody></table>";
                        }
                        ?>
                    </div>
                    <div class="rvt-box__row rvt-button-group">
                        <button class="rvt-button" type="submit">Submit</button>
                    </div>
                </div>
            </form>
        </div>
        <script>
            function experience() {
                var hoursTables = document.getElementById('hours-report');
                var g647Tables = document.getElementById('g647-tables');
                var program = document.getElementById('select-experience');
                console.log(program.value);
                if (program.value == "G647 Advanced Internship") {
                    hoursTables.hidden = true;
                    g647Tables.hidden = false;
                } else {
                    hoursTables.hidden = false;
                    g647Tables.hidden = true;
                }
            }
        </script>

        <?php include "../common/footer.php" ?>

</html>