ALTER TABLE `playerchoice` ADD `KeepOpenAfterChoice` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `HideWarboardHeader`;
ALTER TABLE `playerchoice_response`
  ADD `Flags` int(11) NOT NULL DEFAULT '0' AFTER `ChoiceArtFileId`,
  ADD `WidgetSetID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `Flags`,
  ADD `GroupID` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `WidgetSetID`;
